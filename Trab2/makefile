parametrosCompilacao= #-Wshadow
nomePrograma=main

all: $(nomePrograma)

$(nomePrograma): main.o utils.o trie.o dict.o consulta.o
	gcc -o $(nomePrograma) main.o utils.o trie.o  dict.o consulta.o $(parametrosCompilacao)
	mkdir obj
	mv *.o obj

utils.o: utils.h utils.c
	gcc -c utils.c $(parametrosCompilacao)

trie.o: trie/trie.h trie/trie.c
	gcc -c trie/trie.c $(parametrosCompilacao)

dict.o: dict/dict.h dict/dict.c
	gcc -c dict/dict.c $(parametrosCompilacao)

consulta.o: consulta.h consulta.c
	gcc -c consulta.c $(parametrosCompilacao)

main.o: main.c 
	gcc -c main.c $(parametrosCompilacao)

clean:
	rm -f obj/*.o $(nomePrograma)
	rmdir obj
