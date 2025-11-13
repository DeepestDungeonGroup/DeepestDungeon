clear
if [[ $1 == "-re" ]]
then
    echo "------------RE-BUILD"------------
    rm -rf ./build ./deepest_dungeon
    mkdir ./build/ && cd ./build/
    cmake ..
    cmake --build .
    cd ..
    echo "------------END------------"

elif [[ $1 == "-d" ]]
then
    echo ""------------DEBUG"------------"
    rm -rf ./build ./deepest_dungeon
    mkdir ./build/ && cd ./build/
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    cmake --build . -v
    cd ..
    echo "------------END------------"

elif [[ $1 == "-c" ]]
then
    echo "------------CLEAR------------"
    rm -rf ./build/ ./deepest_dungeon
    echo "------------END------------"

else
    echo "------------BUILD------------"
    if [ ! -d "./build/" ]
    then
        mkdir ./build/ && cd ./build/
        cmake ..
        cd ..
    fi
    cmake --build ./build/
    echo "------------END------------"
fi
