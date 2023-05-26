CY-Shop : main.o produit.o interface.o fichier.o client.o
	gcc -o CY-Shop main.o produit.o interface.o fichier.o client.o

main.o : ./main.c
	gcc -o main.o -c ./main.c

client.o : ./client.c
	gcc -o client.o -c ./client.c

fichier.o : ./fichier.c
	gcc -o fichier.o -c ./fichier.c

interface.o : ./interface.c
	gcc -o interface.o -c ./interface.c

produit.o : ./produit.c
	gcc -o produit.o -c ./produit.c