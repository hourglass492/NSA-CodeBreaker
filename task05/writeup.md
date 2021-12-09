At this point in the investigation we have a solid understanding on what systems the attackers havegained access to, however we do not have a complete understanding on what the attacker is doing within the network. The senerio states that one of the machines that the attacker where able to get access on was a Docker image registry server.

While all images are still on the server, the integrity of the images can not be garanteeded. Only one of the servers have a recent modification date, so our next chalenge is to preform forensic checks on that docker image to ensure that no problems have been introduced to it.

For this challenge we are given a tarball of the docker image with the following directory layout


```
  1 " tar.vim version v29$
  2 " Browsing tarfile /home/user/School_Stuff/CPRE431/Final-Project/NSA-CodeBreaker/task05/image.tar$
  3 " Select a file with cursor and press ENTER$
  4 $
  5 ./$
  6 ./2cc095b0e4503fa1915fc728065d784b233e403cce1cc4ec0964cadf643c6145/$
  7 ./2cc095b0e4503fa1915fc728065d784b233e403cce1cc4ec0964cadf643c6145/VERSION$
  8 ./2cc095b0e4503fa1915fc728065d784b233e403cce1cc4ec0964cadf643c6145/json$
  9 ./2cc095b0e4503fa1915fc728065d784b233e403cce1cc4ec0964cadf643c6145/layer.tar$
 10 ./c261b5b56ecae058351f68268e2cde9d6645d827435e27d6607512e60bb7658d/$
 11 ./c261b5b56ecae058351f68268e2cde9d6645d827435e27d6607512e60bb7658d/VERSION$
 12 ./c261b5b56ecae058351f68268e2cde9d6645d827435e27d6607512e60bb7658d/json$
 13 ./c261b5b56ecae058351f68268e2cde9d6645d827435e27d6607512e60bb7658d/layer.tar$
 14 ./d066676726e6f35bf5fed7b8eef7e425b62221c55260cd3f288bd0fd6d6d96ec/$
 15 ./d066676726e6f35bf5fed7b8eef7e425b62221c55260cd3f288bd0fd6d6d96ec/VERSION$
 16 ./d066676726e6f35bf5fed7b8eef7e425b62221c55260cd3f288bd0fd6d6d96ec/json$
 17 ./d066676726e6f35bf5fed7b8eef7e425b62221c55260cd3f288bd0fd6d6d96ec/layer.tar$
 18 ./d5591dd76f2a9aeb4519ab99ee5edcc679c788ee4d0e624b88feff8f3b308150.json$
 19 ./e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2/$
 20 ./e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2/VERSION$
 21 ./e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2/json$
 22 ./e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2/layer.tar$
 23 ./f8e939bf45f0b3822fadefc9e0b8a1001cbe2f7efbbf6214494ba4155a216bdd/$
 24 ./f8e939bf45f0b3822fadefc9e0b8a1001cbe2f7efbbf6214494ba4155a216bdd/VERSION$
 25 ./f8e939bf45f0b3822fadefc9e0b8a1001cbe2f7efbbf6214494ba4155a216bdd/json$
 26 ./f8e939bf45f0b3822fadefc9e0b8a1001cbe2f7efbbf6214494ba4155a216bdd/layer.tar$
 27 ./manifest.json$
 28 ./repositories

 ```

This required a little bit of research to understand what docker files actually are.

After extensive research online and in the docker offical documents the cliff notes is that XXXXXXXXXXXXXXXXXXX


Using this knowlege we know that it is possible for us to preform both static and dynamic analisis of this docker image to find the flags. Let's first begin by unpacking the tarball and reading through the information included in it.

The first location we looked through where the repositories and manifest.json files held in the root of the tarball. However neither of them supplied much interesting information. 

XXXXXXXXX Posibly include pictures of the file contents


We then moved through reading all of the VERSION and json documents held in what we are assuming in the versioning history or something.

All of the VERSION documents only held ```1.0``` and the json documents however contained slightly more interesting information:

In particular ```./d5591dd76f2a9aeb4519ab99ee5edcc679c788ee4d0e624b88feff8f3b308150.json``` and ```./e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2/json``` contained the actual configuration information for the image.

./e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2/json was the following: 
```
{"id":"e820131f5f0dca9c211faf412e2e80dc081d89b6b5154706a437747aefa19fd2","parent":"d066676726e6f35bf5fed7b8eef7e425b62221c55260cd3f288bd0fd6d6d96ec","created":"2021-07-22T17:45:54.022356331Z","container":"be87a468c2b574d1bf128839de9afa5daf70be831a32a956fb3b604902e86aaa","container_config":{"Hostname":"be87a468c2b5","Domainname":"","User":"","AttachStdin":false,"AttachStdout":false,"AttachStder":false,"Tty":false,"OpenStdin":false,"StdinOnce":false,"Env":["PATH=/usr/local/sbin:/usr/local/bi    n:/usr/sbin:/usr/bin:/sbin:/bin"],"Cmd":["/bin/sh","-c","#(nop) ","LABEL docker.cmd.build=docker bu    ild --no-cache=true --build-arg BUILD_DATE=$(date -u +'%Y-%m-%dT%H:%M:%SZ') --build-arg VCS_REF=$(g    it log -n 1 --abbrev-commit --pretty='%H') ."],"Image":"sha256:71046f97c2f2cb88ae42dad285f457e11292    80accce6adfb7260a5f54f51605b","Volumes":null,"WorkingDir":"/usr/local/src","Entrypoint":null,"OnBui    ld":null,"Labels":{"docker.cmd.build":"docker build --no-cache=true --build-arg BUILD_DATE=$(date -    u +'%Y-%m-%dT%H:%M:%SZ') --build-arg VCS_REF=$(git log -n 1 --abbrev-commit --pretty='%H') .","main    tainer":"harris.emily@panic.invalid","org.opencontainers.image.author":"Emily Harris","org.opencont    ainers.image.created":"2021-03-24T16:53:50Z","org.opencontainers.image.description":"Build and test    s container for PANIC. Runs nightly.","org.opencontainers.image.revision":"be3d94bc8340cc6db649f033    9b7be4abbf2539da","org.opencontainers.image.title":"PANIC Nightly Build and Test"}},"docker_version    ":"20.10.6","config":{"Hostname":"","Domainname":"","User":"","AttachStdin":false,"AttachStdout":fa    lse,"AttachStderr":false,"Tty":false,"OpenStdin":false,"StdinOnce":false,"Env":["PATH=/usr/local/sb    in:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"],"Cmd":["./build_test.sh"],"Image":"sha256:71046f9    7c2f2cb88ae42dad285f457e1129280accce6adfb7260a5f54f51605b","Volumes":null,"WorkingDir":"/usr/local/    src","Entrypoint":null,"OnBuild":null,"Labels":{"docker.cmd.build":"docker build --no-cache=true --    build-arg BUILD_DATE=$(date -u +'%Y-%m-%dT%H:%M:%SZ') --build-arg VCS_REF=$(git log -n 1 --abbrev-c    ommit --pretty='%H') .","maintainer":"harris.emily@panic.invalid","org.opencontainers.image.author"    :"Emily Harris","org.opencontainers.image.created":"2021-03-24T16:53:50Z","org.opencontainers.image    .description":"Build and tests container for PANIC. Runs nightly.","org.opencontainers.image.revisi    on":"be3d94bc8340cc6db649f0339b7be4abbf2539da","org.opencontainers.image.title":"PANIC Nightly Buil    d and Test"}},"architecture":"amd64","os":"linux"}

```

and the ```  ./d5591dd76f2a9aeb4519ab99ee5edcc679c788ee4d0e624b88feff8f3b308150.json ``` contained:
```
{"architecture": "amd64", "config": {"Hostname": "", "Domainname": "", "User": "", "AttachStdin": f    alse, "AttachStdout": false, "AttachStderr": false, "Tty": false, "OpenStdin": false, "StdinOnce":     false, "Env": ["PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"], "Cmd": ["./bui    ld_test.sh"], "Image": "sha256:71046f97c2f2cb88ae42dad285f457e1129280accce6adfb7260a5f54f51605b", "    Volumes": null, "WorkingDir": "/usr/local/src", "Entrypoint": null, "OnBuild": null, "Labels": {"do    cker.cmd.build": "docker build --no-cache=true --build-arg BUILD_DATE=$(date -u +'%Y-%m-%dT%H:%M:%S    Z') --build-arg VCS_REF=$(git log -n 1 --abbrev-commit --pretty='%H') .", "maintainer": "harris.emi    ly@panic.invalid", "org.opencontainers.image.author": "Emily Harris", "org.opencontainers.image.cre    ated": "2021-03-24T16:53:50Z", "org.opencontainers.image.description": "Build and tests container f    or PANIC. Runs nightly.", "org.opencontainers.image.revision": "be3d94bc8340cc6db649f0339b7be4abbf2    539da", "org.opencontainers.image.title": "PANIC Nightly Build and Test"}}, "container": "be87a468c    2b574d1bf128839de9afa5daf70be831a32a956fb3b604902e86aaa", "container_config": {"Hostname": "be87a46    8c2b5", "Domainname": "", "User": "", "AttachStdin": false, "AttachStdout": false, "AttachStderr":     false, "Tty": false, "OpenStdin": false, "StdinOnce": false, "Env": ["PATH=/usr/local/sbin:/usr/loc    al/bin:/usr/sbin:/usr/bin:/sbin:/bin"], "Cmd": ["/bin/sh", "-c", "#(nop) ", "LABEL docker.cmd.build    =docker build --no-cache=true --build-arg BUILD_DATE=$(date -u +'%Y-%m-%dT%H:%M:%SZ') --build-arg V    CS_REF=$(git log -n 1 --abbrev-commit --pretty='%H') ."], "Image": "sha256:71046f97c2f2cb88ae42dad2    85f457e1129280accce6adfb7260a5f54f51605b", "Volumes": null, "WorkingDir": "/usr/local/src", "Entryp    oint": null, "OnBuild": null, "Labels": {"docker.cmd.build": "docker build --no-cache=true --build-    arg BUILD_DATE=$(date -u +'%Y-%m-%dT%H:%M:%SZ') --build-arg VCS_REF=$(git log -n 1 --abbrev-commit     --pretty='%H') .", "maintainer": "harris.emily@panic.invalid", "org.opencontainers.image.author": "    Emily Harris", "org.opencontainers.image.created": "2021-03-24T16:53:50Z", "org.opencontainers.imag    e.description": "Build and tests container for PANIC. Runs nightly.", "org.opencontainers.image.rev    ision": "be3d94bc8340cc6db649f0339b7be4abbf2539da", "org.opencontainers.image.title": "PANIC Nightl    y Build and Test"}}, "created": "2021-03-24T16:53:50.614565Z", "docker_version": "20.10.6", "histor    y": [{"created": "2021-03-24T16:53:26.794175Z", "comment": " "}, {"created": "2021-03-24T16:53:30.6    01621Z", "created_by": "/bin/sh -c #(nop)  CMD [\"/bin/sh\"]", "empty_layer": true}, {"created": "2    021-03-24T16:53:45.732897Z", "created_by": "/bin/sh -c apk add     automake     glib-dev     gtk-do    c     libtool     expat     expat-dev     gobject-introspection-dev     wget     autoconf     libgc    c      libstdc++      gcc      g++      git"}, {"created": "2021-03-24T16:53:48.333722Z", "created_    by": "/bin/sh -c #(nop) WORKDIR /usr/local/src"}, {"created": "2021-03-24T16:53:48.498444Z", "creat    ed_by": "/bin/sh -c #(nop) ADD file:ace8e311b8ce235d70a132c426ab43723b6830cd9e762735c1bdc9895549d30    d in ./build_test.sh "}, {"created": "2021-03-24T16:53:49.138114Z", "created_by": "/bin/sh -c chmod     +x ./build_test.sh"}, {"created": "2021-03-24T16:53:49.275018Z", "created_by": "/bin/sh -c #(nop)      CMD [\"./build_test.sh\"]", "empty_layer": true}, {"created": "2021-03-24T16:53:49.421566Z", "crea    ted_by": "/bin/sh -c #(nop)  ARG BUILD_DATE", "empty_layer": true}, {"created": "2021-03-24T16:53:4    9.580054Z", "created_by": "/bin/sh -c #(nop)  ARG VCS_REF", "empty_layer": true}, {"created": "2021    -03-24T16:53:49.718531Z", "created_by": "/bin/sh -c #(nop)  LABEL maintainer=harris.emily@panic.inv    alid", "empty_layer": true}, {"created": "2021-03-24T16:53:49.862466Z", "created_by": "/bin/sh -c #    (nop)  LABEL org.opencontainers.image.created=2021-03-24T16:53:50Z", "empty_layer": true}, {"create    d": "2021-03-24T16:53:50.018609Z", "created_by": "/bin/sh -c #(nop)  LABEL org.opencontainers.image    .revision=be3d94bc8340cc6db649f0339b7be4abbf2539da", "empty_layer": true}, {"created": "2021-03-24T    16:53:50.163686Z", "created_by": "/bin/sh -c #(nop)  LABEL org.opencontainers.image.title=PANIC Nig    htly Build and Test", "empty_layer": true}, {"created": "2021-03-24T16:53:50.317688Z", "created_by"    : "/bin/sh -c #(nop)  LABEL org.opencontainers.image.description=Build and tests container for PANI    C. Runs nightly.", "empty_layer": true}, {"created": "2021-03-24T16:53:50.463047Z", "created_by": "    /bin/sh -c #(nop)  LABEL org.opencontainers.image.author=Emily Harris", "empty_layer": true}, {"cre    ated": "2021-03-24T16:53:50.614565Z", "created_by": "/bin/sh -c #(nop)  LABEL docker.cmd.build=dock    er build --no-cache=true --build-arg BUILD_DATE=$(date -u +'%Y-%m-%dT%H:%M:%SZ') --build-arg VCS_RE    F=$(git log -n 1 --abbrev-commit --pretty='%H') .", "empty_layer": true}], "os": "linux", "rootfs":     {"type": "layers", "diff_ids": ["sha256:9d1ff88442b24cd33ce56a2d430ed1c4e59eb4a2b2045669c62017d574    102f2c", "sha256:e9c57e1437e5bd09dc55b23bf698036f7fa1945720d74404fce2530429008407", "sha256:f47ff8a    fed564ca1db4244825873aa8932ed42ffe90e46c36af8753d591c8e16", "sha256:642a6b4c349aaf084f99b99c381dded    f6cd23c13caca18b5e2c11bdbfde77347", "sha256:16ede67dfce342d8cd41fd9273fbfbba8e2dde410ea3a784ef045b8    d770f381a"]}}
```

Parsing through this data we are able to find the first flag which in my case was:

Flag1: harris.emily@panic.invalid


Both of these flags were submitted to portal to conferm they were correct to insure that we were on the correct track. Luckally we were and were able to continue forward.

At this point there are 2 paths to find the final flags and we will walk through both of them.

### Dynamic Analisis methiod

### Static analisis methiod
As we learned earlier, docker images contain all of the files that will run in the image when it starts. Because we know that this docker image must download the code from a git repository on start up we can assume that there is some sort of startup script within the docker image that runs on creation. We can guess that this code downloads the remote git repo and then preforms some sort of checks with it.

To find the remote github repo then we need to navigate through the many different files contained within the given tarball. To do that we will first unpack the first tarball to allow vim to properly parse the lower layered tarballs.

This can easly be done with `tar xvf image.tar` and we can begin to look through all of the files.


XXXXXXXXXXXXXX Talk about the lack of rc or cron jobs stuff and other standard malware persistance locations XXXXXXXXXXXXXXXXXXXXXxx

These methiods did not work so we returned to reading through the documentation about docker images and discovered that images can be configured to run comands when they are started. Upon looking through the larger json file we found the following ` "Cmd":["./build_test.sh"]," `. This lets us know that there is some script that builds something which is what we are looking for. To find this script we simply unpack all 4 of the tarballs and use `find . -iname build_test.sh` which returns the location of the script. 

Once we open it we get the following:

```
#!/bin/bash

git clone https://git-svr-41.prod.panic.invalid/hydraSquirrel/hydraSquirrel.git repo

cd /usr/local/src/repo

./autogen.sh

make -j 4 install

make check
```

This gives us the second flag.

Looking through the script we get a better understanding of what this docker container does. Once it starts it downloads the source code to to /usr/local/src/repo, runs the autogen.sh script held in the repo and then calls make install with -j 4 as options and then calls make check.

This seems like a pretty standard methiod to install an application from source code which makes sense.


Now that we have the 2nd flag, let's pivot to looking for where the malware is on the image.

To find the malware I had to make some assumptions. First we can do some metagaming by looking at the next two challenges. It is clear that we will have to reverse engineer this malware to figure out what it does. We can also assume that because this is a challenge aimed towoards students it will not be an incredibly difficult reverse engineering challenge. This means that there is a very high chance that the binary will not be stripped. To find all non striped exicutable files in the directory, we will simply run 

`XXXXXXXX TODO XXXXXXXXXXXXX`

which returns

```
XXXXXXXXXXXXXXXXXX TODO XXXXXXXXXXXXXXXx
```

This gives us a relitivly small list of files that would be possible to brute force the submition portal with. However, it's possible to read through this list and use logic to figure out which file is most likely the malware. We can see that many of these files are related to the same package. This means that the package maintainer probably just ships out non stripped binaries for some reason. 
Scanning through all of the files we see make at the bottom. We already know that the build script calls make twice on startup, so it makes sense that it could be malisus. Also checking make on my system I see it is not normally stripped. Finally it makes sense that make would be the malicusus file from a CTF perspective. The authors could logically think that the participants would look at the files refrenced in the build_test.sh script because that is where the last flag was.

Upon submitting the path to make, we succseed the challange.
