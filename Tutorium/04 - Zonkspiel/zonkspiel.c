/*
Tutoriumsübung 04 - Zonkspiel

Das Programm führt folgendes Standardsetup durch:
	*	Erstellung von 3 Türen
	*	zufällige Belegung der Türen mit 2 Zonks und einem Preis
	*	Durchführung des Tastatursetups

Anschließend wird folgender Ablauf durchgeführt:
	1.	User wird nach Auswahl gefragt
	2.	Eine zufällige andere Tür wird geöffnet (darf nicht den Preis enthalten)
	3.	Der User wird gefragt ob er seine Auswahl ändern möchte
	4.	Das Resultat wird angezeigt

Notes:
	*	WICHTIG: bei Änderungen asciiToDoor überprüfen und ggf. anpassen/erweitern!
	*	Quelle ASCII Oktalwerte:	asciitable.com
*/


// defines for game & Showmaster
#define GAMEDIV "***************************************************"
#define SMDIV "=============================="
#define SMINTRO "Willkommen bei \"GEH AUFS GANZE\"!!!!!"
#define SMRULES "Und hier sind die Regeln:\nSie suchen sich jetzt ein Tor aus und dann schauen wir mal ob Sie gewonnen haben!"
#define SMASKDOOR "Für welches Tor haben Sie sich entschieden?"
#define SMERROR "Ups, da ist irgendetwas schiefgelaufen!\nProbieren wir es gleich noch einmal!"
#define SMCHOSEN "OK, Sie haben sich Tor %d ausgesucht.\n"
#define SMHINTDOORS "Geben Sie einen Wert zwischen 1 und 3 ein"
#define SMPREOPEN "Sehr gut. Dann wollen wir Ihnen mal zeigen was Sie nicht gewählt haben:"
#define SMNOTCHOSEN "Sie haben Tor %d nicht gewählt. Glück gehabt, es enthielt den Zonk!\n"
#define SMPRESWITCH "Sooooo und nun kommen wir zur Frage des Abends:"
#define SMSWITCH "Möchten Sie Ihr jetziges Tor gegen das andere tauschen?"
#define SMNOSWITCH "Alles klar, dann bleiben Sie eben bei Ihrer ersten Wahl!"
#define SMSWITCHED "Gute so! Ihr neues Tor lautet: %d\n"
#define SMHINTSWITCH "Geben Sie y für \"ja\" oder n für \"nein\" ein"
#define SMPREREVEAL "*TROMMELWIRBEL* und nun verraten wir mit was für einem Preis Sie heute nach Hause gehen!"
#define SMWIN "Herzlichen Glückwunsch!!!! Sie haben den Hauptpreis gewonnen!"
#define SMLOST "Schade, in Ihrem Tor war leider der Zonk.... Aber lassen Sie Ihren Kopf nicht hängen, das Ding bekommt irgendwann Kultstatus!"
#define SMENDGAME "Vielen Dank für's mitspielen, bis zum nächsten mal!"

// defines for dev
#define DEVDIV "###################################"
#define REVEALDOOR "Inhalt Tor %d: %s\n"

// defines for Keyboard Setup
#define SMKBSETUP "Doch bevor wir loslegen können müssen wir noch schnell das Tastatursetup durchführen...\nDafür drücken Sie auf Ihrer Tastatur die angezeiten Tasten und bestätigen mit ENTER."
#define KBASKKEY "Bitte drücken Sie die Taste \"%s\": "
#define KBCMPLT "Super dann kann es jetzt endlich losgehen. Viel Spaß!"

// defines for game env.
#define NUMOFDOORS 3
#define INPUTCACHESIZE 1
#define ZONK "Z"
#define PRIZE "P"


// needed includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main () {
	//basic setup START
	unsigned int seed;
	char c;
	char* doors[] = {ZONK, ZONK, ZONK};
	unsigned int randNum;
	int answer = 0;
	int doorChosen = 0;
	int doorToOpen;
	int doorWithPrize;
	int i;
	int key1;
	int key2;
	int key3;
	int keyY;
	int keyN;
	// basic setup END

	// gamestart
	puts(GAMEDIV);
	puts(GAMEDIV);

	// Showmaster Intro
	puts(SMDIV);
	puts(SMINTRO);
	puts(SMDIV);
	puts(SMRULES);
	puts(SMDIV);
	puts(SMKBSETUP);
	puts(SMDIV);



	// Keyboardsetup START
	while (1) {
		// set keys to 0
		key1 = 0;
		key2 = 0;
		key3 = 0;
		keyY = 0;
		keyN = 0;

		// key 1
		printf(KBASKKEY, "1");
		while ((c = getchar()) != '\n') {
			if (!key1) {key1 = c;}
		}

		// key 2
		printf(KBASKKEY, "2");
		while ((c = getchar()) != '\n') {
			if (!key2 && (c != key1)) {key2 = c;}
		}

		// key 3
		printf(KBASKKEY, "3");
		while ((c = getchar()) != '\n') {
			if (!key3 && (c != key1) && (c != key2)) {key3 = c;}
		}

		// key y
		printf(KBASKKEY, "y");
		while ((c = getchar()) != '\n') {
			if (!keyY && (c != key1) && (c != key2) && (c != key3)) {keyY = c;}
		}

		// key n
		printf(KBASKKEY, "n");
		while ((c = getchar()) != '\n') {
			if (!keyN && (c != key1) && (c != key2) && (c != key3) && (c != keyY)) {keyN = c;}
		}

		puts(SMDIV);


		// Überprüfung Setup
		if (key1 && key2 && key3 && keyY && keyN) {
			puts(KBCMPLT);
			break;
		} else {
			puts(SMERROR);
		}
	}

	puts(SMDIV);
	// Keyboardsetup END



	// Gamesetup START
	seed = time(NULL);
//	printf("Seed 1: %d\n", seed);	// uncomment for seed debugging

	// assign prize to a random door
	randNum = rand_r(&seed);
	doorWithPrize = randNum % 3;
	doors[doorWithPrize] = PRIZE;
	// Gamesetup END



	// einlesen der Tür inkl. Bestätigung
	while (1) { //Schleife wird ausgeführt bis eine gültige Tür gewählt wurde

		// Einlesen der Tür
		puts(SMASKDOOR);
		puts(SMDIV);
		while((c = getchar()) != '\n' && c != EOF) {
			if ((c == key1) && !doorChosen) {
				doorChosen = 1;
			} else if ((c == key2) && !doorChosen) {
				doorChosen = 2;
			} else if ((c == key3) && !doorChosen) {
				doorChosen = 3;
			}
		}

		// Schleifenende falls erfolgreiche Eingabe sonst Fehlermeldung & Neustart
		if (doorChosen) {
			puts(SMDIV);
			printf(SMCHOSEN, doorChosen);
			break;
		} else {
			puts(SMERROR);
			puts(SMHINTDOORS);
		}
	}


	// Öffnen eines zufälligen Zonk-Tores
	puts(SMPREOPEN);
	randNum = rand_r(&randNum);
//	printf("\n%d\n", randNum);	//uncomment for seed debugging
	while (1) {
		// Tor generieren
		doorToOpen = randNum %3;

		// überprüfe Userauswahl
		if (doorToOpen != (doorChosen - 1) && strcmp(doors[doorToOpen], PRIZE)) {
			printf(SMNOTCHOSEN, (doorToOpen +1));
			break;
		}

		// bei Misserfolg randNum inkrementieren
		randNum++;
	}

	// Nachfrage zwecks switchen
	puts(SMDIV);
	puts(SMPRESWITCH);
	//	Einlesen START
	while (1) {
		puts(SMSWITCH);
		puts(SMDIV);

		while ((c = getchar()) != '\n' && c != EOF) {
			if (c == keyY && !answer) {
				answer = keyY;
			} else if (c == keyN && !answer) {
				answer = keyN;
			}
		}

		puts(SMDIV);

		// Schleifenende falls erfolgreich
		if (answer == keyN) {
			// Tausch verweigert
			puts(SMNOSWITCH);
			break;
		} else if (answer == keyY) {
			// Tausch durchführen
			for (i=1; i<=NUMOFDOORS; i++) {
				if (i != doorChosen && i != (doorToOpen +1)) {
					doorChosen = i;
					break;
				}
			}

			printf(SMSWITCHED, doorChosen);
			break;
		} else {
			puts(SMERROR);
			puts(SMHINTSWITCH);
		}
	} 	// Einlesen END

	puts(SMDIV);
	puts(SMPREREVEAL);
	puts(SMDIV);

	// Ausgabe des Ergebnisses
	if (strcmp(doors[(doorChosen - 1)], ZONK)) {
		puts(SMWIN);
	} else {
		puts(SMLOST);
	}

	puts(SMDIV);
	puts(SMENDGAME);
	puts(GAMEDIV);
	puts(GAMEDIV);

	// coding help
	puts(DEVDIV);
	for (i=0;i<=2;i++) {
		printf(REVEALDOOR, (i+1), doors[i]);
	}
	puts(DEVDIV);
	return 0;
}
