% Help:
%Lo script effettua la risoluzione di 10 sistemi lineari di dimensione
%crescente da 100 a 1000 tramite gli algoritmi di Jacobi e Gauss-Seidel. 
%In output verranno stampati gli errori relativi e i numeri di 
%condizionamento di ognuna delle 10 matrici generate.


clc

fprintf("Metodo\t\tDimensione\t\tErrore Relativo\t\tRaggio Spettrale\n")

for n = 100 : 100 : 1000 % ciclo for da 100 a 1000 con passo 100
    A = rand(n); % creazione di una matrice con elementi pseudocasuali
    A = A-diag(diag(A)); %rimozione della diagonale dalla matrice
    sum_row = abs(A)*ones(n,1); % calcolo delle somme riga
    k = 2; % fattore di predominanza
    A = A + k*diag(sum_row); % calcolo della matrice diagonalmente dominante
    x = ones(n, 1); % creazione del vettore colonna contenente soli 1
    b = A*x; % creazione del vettore b dei termini noti con prodotto tra A e x
    x0 = zeros(n,1); % creazione del vettore colonna contenente soli 0
    tol = 1e-10; % pongo la tolleranza a 1e-10
    k_max = 1000; % pongo numero di iterazioni massime a 1000

    % invocazione della funzione jacobi, restituirà la soluzione approssimativa,
    % il numero di iterazioni effettuate e il raggio spettrale, prendendo come input
    % la matrice, il vettore dei termini noti, la tolleranza, il numero
    % massimo di iterazioni e il vettore iniziale
    [x_j, k_j, rho_j] = jacobi(A, b, tol, k_max, x0); 
    
    % invocazione della funzione gs, restituirà la soluzione approssimativa,
    % il numero di iterazioni effettuate e il raggio spettrale, prendendo come input
    % la matrice, il vettore dei termini noti, la tolleranza, il numero
    % massimo di iterazioni e il vettore iniziale
    [x_gs, k_gs, rho_gs] = gs(A, b, tol, k_max, x0);
    
    % calcolo dell'errore relativo della soluzione approssimativa calcolata con
    % jacobi
    err_j = ((norm(x-x_j))/(norm(x)));
    
    % calcolo dell'errore relativo della soluzione approssimativa calcolata con
    % gauss-seidel
    err_gs = ((norm(x-x_gs))/(norm(x)));

    fprintf("Jacobi\t\t %d \t\t\t%e\t\t%e\n", n, err_j, rho_j);
    fprintf("Gauss-Seidel\t %d \t\t\t%e\t\t%e\n", n, err_gs, rho_gs);
    fprintf("\n");

end