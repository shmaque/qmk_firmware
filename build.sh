## qmk helper
## Plancks
#qmk compile -km shmaque -kb planck/rev4 &&
#qmk compile -km shmaque -kb planck/rev6 &&
## Preonic
#qmk compile -km shmaque -kb preonic/rev3

##Make
## Plancks
#make planck/rev4:shmaque &&
#make planck/rev6:shmaque &&
## Preonic
#make preonic/rev3:shmaque

#Docker 
# Plancks
util/docker_arm_build.sh planck/rev4:shmaque &&
util/docker_arm_build.sh planck/rev6:shmaque &&
# Preonic
util/docker_arm_build.sh preonic/rev3:shmaque
