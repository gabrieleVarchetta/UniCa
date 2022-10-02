function [P,L,U] = gauss_palu(A)

% Help:
% questa funzione rende la fattorizzazione PA=LU di una matrice senza struttura
% l'input e' la matrice da fattorizzare
% gli output sono le matrici P, L e U tali che P*A = L*U

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

% Creazione della matrice di permutazione partendo dalla matrice identità
P = eye(n); 

% Applicazione di gauss con pivoting per rendere la matrice a gradini (U) e
% fare gli eventuali scambi nella matrice dei moltiplicatori L
for k = 1:n-1
    [~,pos] = max(abs(A(k:n,k))); % Ricerca dell'elemnto massimo nella colonna considerata dal for
    r = pos + k - 1; % Ricerca della riga di appartenenza dell'elemento massimo
    A([k r],:) = A([r k],:); % Effettuo scambio nella matrice A
    P([k r],:) = P([r k],:); % Effettuo scambio nella matrice P
    L([k r],:) = L([r k],:); % Effettuo scambio nella matrice L
    for i = k+1:n
    	m = A(i,k)/A(k,k); % Calcolo moltiplicatore
    	A(i,:) = A(i,:) - m*A(k,:); % Sostituzione della riga con la riga stessa
                                    % sottratto al moltiplicatore * riga
                                    % pivot
    	L(i,k) = m; % Inserimento del moltiplicatore nella matrice L
    end
end

% Salvataggio della matrice in U dato che A è già triangolare superiore
U=A;

% Inserimento degli 1 nella diagonale della matrice dei moltiplicatori
L = L + diag(ones(n,1));