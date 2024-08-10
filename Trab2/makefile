parametrosCompilacao= #-Wshadow
nomePrograma=dicionario

all: $(nomePrograma)

$(nomePrograma): main.o utils.o trie.o dict.o consulta.o
	gcc -o $(nomePrograma) main.o utils.o trie.o  dict.o consulta.o $(parametrosCompilacao)

utils.o: utils.h utils.c
	gcc -c utils.c $(parametrosCompilacao)

trie.o: trie.h trie.c
	gcc -c trie.c $(parametrosCompilacao)

dict.o: dict.h dict.c
	gcc -c dict.c $(parametrosCompilacao)

consulta.o: consulta.h consulta.c
	gcc -c consulta.c $(parametrosCompilacao)

main.o: main.c 
	gcc -c main.c $(parametrosCompilacao)

clean:
	rm -f *.o $(nomePrograma)
