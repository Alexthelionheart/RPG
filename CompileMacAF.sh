now=`date +'%m%d%Y'`

echo $now

echo "Compiling"
clang++ Code/*.cpp -std=c++11  -framework sfml-system -framework sfml-window -framework sfml-network -framework sfml-graphics -framework sfml-audio -o "Build/GameBuild-$now.out"     
echo "copying assets"
cp -f -r Assets/* Build/
echo "Done the game was compiled as an .out file  Build/GameBuild-$now.out"

