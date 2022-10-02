%Ripulisce la command window
clc

%Prende in input un numero e lo salva nella variabile
n = input("Inserire una dimensione: ");

%Crea una matrice quadrata di dimensione n con elementi casuali interi tra 10 e 20 
S = randi([10, 20], n)

%Controlla se la matrice è simmetrica o meno, se lo è stampa un messaggio,
%altrimenti effettua delle operazioni per renderla simmetrica e la mostra a
%schermo
if(issymmetric(S))
    disp("La matrice S è simmetrica.");
else
    disp("Matrice S simmetrizzata: ");
    S = (S + S') / 2
end

%Calcolo degli autovalori di S e salvataggio degli autovalori in una
%variabile
d = eig(S)

%Calcolo della norma 1
norm1 = norm(d, 1)

%Calcolo della norma 2
norm2 = norm(d, 2)

%Calcolo della norma infinito
normInf = norm(d, Inf)