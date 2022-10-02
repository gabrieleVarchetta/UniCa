%Ripulisce la command window
clc

%Provando a inserire numeri a caso, potrebbe accadere che i due risultati
%coincidano. Per testare lo script vengono usati i valori consigliati su
%e-learning
%a = input("Inserire primo numero: ");
%b = input("Inserire secondo numero: ");
%c = input("Inserire terzo numero: ");

%Creazione e inizializzazione delle tre variabili non normalizzate usate nelle equazioni
a = 72.213;
b = 41.243;
c = -113.44;

%Creazione e inizializzazione delle due equazioni non normalizzate
d1 = (a+b)+c;
d2 = a+(b+c);

%Creazione e inizializzazione delle tre variabili normalizzate usate nelle
%due equazioni normalizzate
aNorm = round(a, 3, 'significant');
bNorm = round(b, 3, 'significant');
cNorm = round(c, 3, 'significant');

%Creazione delle due equazioni normalizzate
d1Norm = round((round((aNorm+bNorm), 3, 'significant') + cNorm), 3, 'significant');
d2Norm = round(aNorm + (round((bNorm+cNorm), 3, 'significant')), 3, 'significant');

%Stampa a schermo dei risultati delle due equazioni non normalizzati
fprintf("\nIl risultato di (a + b) + c non normalizzato e non arrotondato e': %f.\n", d1);
fprintf("Il risultato di a + (b + c) non normalizzato e non arrotondato e': %f.\n", d2);

%Stampa a schermo dei risultati delle due equazioni normalizzati
fprintf("\nIl risultato di (a + b) + c normalizzato e arrotondato e': %f.\n", d1Norm);
fprintf("Il risultato di a + (b + c) normalizzato e arrotondato e': %f.\n", d2Norm);

%Calcolo degli errori relativi
p1 = abs(((a+b)+c) - d1Norm)/abs((a+b)+c);
p2 = abs((a+(b+c)) - d2Norm)/abs(a+(b+c));

%Stampa degli errori relativi
fprintf("\nL'errore relativo p1 e': %e.\n", p1);
fprintf("L'errore relativo p2 e': %e.\n", p2);