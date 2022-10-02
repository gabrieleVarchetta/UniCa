%Ripulisce la command window
clc

%Prende in input un numero e lo salva nella variabile
n = input("Inserire una dimensione: ");

%Crea una matrice quadrata di dimensione n contenente numeri pseudocasuali
%tra 0 e 1
R = rand(n)

%Estrae la diagonale dalla matrice R e la salva in un vettore
x = diag(R)

%Crea una matrice che come diagonale ha il vettore x e il resto degli
%elementi sono 0 (matrice diagonale)
D = diag(x)

%Crea una matrice estraendo la parte superiore dalla matrice R, creando
%dunque una matrice triangolare superiore
U = triu(R)

%Crea una matrice estraendo la parte inferiore dalla matrice R, creando
%dunque una matrice triangolare inferiore
L = tril(R)

%Stampa dei messaggi a schermo a seconda che la condizione sia verificata o
%meno, le funzioni controllano rispettivamente che la matrice passata come
%parametro sia diagonale, triangolare superiore o inferiore
if(isdiag(D))
    disp("La matrice D è diagonale.");
else
    disp("La matrice D non è diagonale.")
end

if(istriu(U))
    disp("La matrice U è triangolare superiore.");
else
    disp("La matrice U non è triangolare superiore.");
end

if(istril(L))
    disp("La matrice L è triangolare inferiore.");
else
    disp("La matrice L non è triangolare inferiore.");
end