function [L,U] = gauss_lu(A)

% Help:
% questa funzione rende la fattorizzazione A=LU di una matrice senza struttura
% l'input e' la matrice da fattorizzare
% gli output sono le matrici L e U tali che A = L*U

format rat

%Salvataggio in due variabili del numero di righe e colonne di A
[m,n] = size(A);

% Se righe e colonne non sono uguali allora non è quadrata
if (m~=n)
    error('Matrice non quadrata!')
end

% Se det < 1e-14 allora il determinante è piccolo
if (abs(det(A)) < 1e-14)
    error('Determinante molto piccolo')
end

% Creazione della matrice L di zeri
L = zeros(n); 

% Aggiornamento della matrice dei moltiplicatori inserendo solo gli 1
L = L + diag(ones(n,1)); 

% Applicazione di gauss naive, calcolando la matrice a gradini di A
% e inserendo i moltiplicatori nella matrice L
for k = 1:n-1
    for i = k+1:n
    	m = A(i,k)/A(k,k); % Calcolo moltiplicatore
    	A(i,:) = A(i,:) - m*A(k,:); % Sostituzione della riga in considerazione con la differenza
                                    % tra la riga stessa e il prodotto tra
                                    % moltiplicatore e la riga del pivot
    	L(i,k) = m;
    end
end

% Salvataggio del risultato in U
U=A;


