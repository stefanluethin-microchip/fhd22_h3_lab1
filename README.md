#-SL main branch first line
Simple Harmony3 example to
 a) toggleLED @250ms
 b) print msg on terminal

HW used: https://www.microchip.com/en-us/development-tool/atsamd21-xpro

Physical setup shown in 'h3_lab1_samd21_phySetup.jpg'
Expected result shown in 'h3_lab1_samd21_expResult.jpg'

Used for FH-Dortmund Session Nov.2022


Steps to create initial git-repo:
 1) created repo online in https://github.com/stefanluethin-microchip
 2) created all files and place locally into 
    C:\mchp\0cust\FHDortmund\2212xx_Vorlesung\Solutions\fhd22_h3_lab1\
 3) open gitbash here and exec'd these steps in 
    'M16422@DEM-LT-M16422B: /c/mchp/0cust/FHDortmund/2212xx_Vorlesung/Solutions/fhd22_h3_lab1/'
    $ git init
        Initialized empty Git repository in C:/mchp/0cust/FHDortmund/2212xx_Vorlesung/Solutions/fhd22_h3_lab1/.git/

    $ git add *
        warning: LF will be replaced by CRLF in h3_lab1_samd21/firmware/samd21_lab1.X/Makefile.
        The file will have its original line endings in your working directory
        warning: LF will be replaced by CRLF in h3_lab1_samd21/firmware/samd21_lab1.X/mcc_h3_p1.mc3.
        The file will have its original line endings in your working directory
        
    $ git commit -m "H3 lab1 (first commit)"
        [master (root-commit) daa5929] H3 lab1 (first commit)
        111 files changed, 32699 insertions(+)
        create mode 100644 LICENSE
        create mode 100644 README.md
        create mode 100644 h3_lab1_samd21/firmware/samd21_lab1.X/Makefile
        ...
        create mode 100644 h3_lab1_samd21/firmware/src/packs/CMSIS/CMSIS/Core/Include/core_cm0plus.h
        create mode 100644 h3_lab1_samd21/firmware/src/packs/CMSIS/CMSIS/Core/Include/mpu_armv7.h
        create mode 100644 h3_lab1_samd21_expResult.jpg
        create mode 100644 h3_lab1_samd21_phySetup.jpg

    $ git branch -M main
    
    $ git remote add origin https://github.com/stefanluethin-microchip/fhd22_h3_lab1.git
    
    $ git push -u origin main
        Enumerating objects: 139, done.
        Counting objects: 100% (139/139), done.
        Delta compression using up to 12 threads
        Compressing objects: 100% (131/131), done.
        Writing objects: 100% (139/139), 3.96 MiB | 3.92 MiB/s, done.
        Total 139 (delta 53), reused 0 (delta 0), pack-reused 0
        remote: Resolving deltas: 100% (53/53), done.
        To https://github.com/stefanluethin-microchip/fhd22_h3_lab1.git
        * [new branch]      main -> main
        Branch 'main' set up to track remote branch 'main' from 'origin'.

 See 'h3_lab1_samd21_repoDone.jpg' how online-repo now looks like
 To work with this repo now in SourceTree do:
   1) open SourceTree
   2) add new tab = new repo
      path-2-repo: C:\mchp\0cust\FHDortmund\2212xx_Vorlesung\Solutions\fhd22_h3_lab1
      repoe-name:  'filled out automatically, as repo already create with gitbash above'
      Local folder: [root] -> filled out
      -> hit 'Add'  => see 'h3_lab1_samd21_repoSourceTree-init.jpg'
   3) now work with SourceTree 
        -> see 'h3_lab1_samd21_repoSourceTree-work.jpg'

Author: stefan.luethin@microchip.com (SL, 24.10.2022)
