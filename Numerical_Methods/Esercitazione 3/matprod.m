%Ripulisce la command window
clc

%Richiesta di un numero in input e salvataggio del numero nella variabile
n = input("Inserire una dimensione: ");

%Creazione di una matrice quadrata di dimensione n contenente solo 0
A = zeros(n);

%Creazione di una matrice quadrata di dimensione n contenente solo 1
B = ones(n);

%Creazione di un vettore colonna con n righe e una colonna, contenente solo
%2
z = ones(n, 1) * 2;

%Stampa delle matrici e del vettore a schermo
disp("Matrice quadrata A di dimensione n di soli zeri:");
disp(A);

disp("Matrice quadrata B di dimensione n di soli uni:");
disp(B);

disp("Vettore colonna z di dimensione n di soli due:");
disp(z);

%Calcolo dei prodotti e salvataggio nelle variabili dei risultati
b = A * z;
c = z' * B;

%Stampa dei risultati dei prodotti
disp("Prodotto A per z:");
disp(b);

disp("Prodotto z' per B:");
disp(c);