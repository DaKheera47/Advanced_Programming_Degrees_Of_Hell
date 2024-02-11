# actually build first
./scripts/build.sh;
# then check for leaks
leaks -atExit -- ./dist/DegreesOfHell;