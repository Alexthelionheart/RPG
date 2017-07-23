

all:
	clang++ Code/*.cpp -std=c++11  -framework sfml-system -framework sfml-window -framework sfml-network -framework sfml-graphics -framework sfml-audio -o "Build/game"   
	echo "copying assets"
	cp -f -r Assets/* Build/	

cleanup: 
	rm -fr Build/*
