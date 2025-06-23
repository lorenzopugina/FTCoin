make          Para compilar
make run      Para executar
make clean    Para limpar

tem q estar na pastar FTCOIN (não pode entrar no src)

g++ src/*.cpp src/Controller/*.cpp src/Model/*.cpp src/Utils/*.cpp src/View/*.cpp src/DAO/inMemory/*.cpp -I src/Controller -I src/Model -I src/Utils -I src/View -I src/DAO/inMemory -I src/DAO/interface -o programa