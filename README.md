# CryptStore_data
This repository is created for CryptStore project.

# CryptStore project

## Define
CryptStore is a digital safe protect by passphrase.
Password is split in k other password given in other people (eg: familly)
by algorythm of Shamir's Secret Sharing (https://en.wikipedia.org/wiki/Shamir%27s_Secret_Sharing).

If someone need to acces of safe, we need (k / 2) password for unlock this.

All familly safe are synchronyse each one by p2p system (home protocol).
Each member have save of other member, but juste the owner can modify the safe.

For example :

French
```
3 personnes de confiance Alice Bob et Marc
Chacun possede un coffre numerique proteger par mot/phrase de passe
et chacun possede une copie du coffre des 2 autres

A chaque fois que le contenue d'un coffre est modifie, il se syncronise avec les copies
Les coffres permettent de contenir tous les documents vitaux tel que: CNI, base keepass, document impot, etc..
Maintenant si Alice pert son password (deces, perte de memoire dut a un traumatisme, etc)
Marc et Bob peuvent ce retrouver pour recuperer le mot/phrase de passe de Alice
maintenant autre cas:
Bob ce fait voler son pc
Il peut quand meme recupere ces documents important grace au copie de son coffre detenue par Marc et Alice
```

English
```
3 people confident Alice Bob and Marc
each of one have a digital safe protected by passphrase and each of one have safe copy of other members.

each time when safe is modifing, it sync with a copy.
Safe can save vital records (CNI, Keepass base, gouvernment administration, ...)
Now if Alice lost her password (dead, lost memory after accident, ...), Marc and Bob can meet for recover password of Alice.
Now next case, if Bob are stolen his portable, he can recover their documents through copy of Alice or Marc
```

## Project repository
This project repository isn't finaly project, it's just a split functionnality for
simply unit test and modification.

## Functionnality
./crypto_store [d|out] file

-> options :
	`-d: debug`
	`--out=<file directory>: write key in file directory`