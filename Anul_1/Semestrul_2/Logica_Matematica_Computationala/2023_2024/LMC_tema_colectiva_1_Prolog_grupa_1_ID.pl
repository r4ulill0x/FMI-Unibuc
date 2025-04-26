% rezolvari tema colectiva Grupa 1 Informatica ID 2023-2024

:-[lab3lmc2].


%>>>>>>>>> EXERCITIUL 1 
% (A<=B)<=>(A<B sau A=B)

ex1 :- not((pereche(A,B), not(echiv(implica(A,B),(inclstr(A,B);echiv(A,B)))))).

%>>>>>>>>> EXERCITIUL 2
% (A<=B<C => A<C) si (A<B<C => A<C)

ex2 :- not((triplet(A,B,C), not((implica((implica(A,B), inclstr(B,C)), inclstr(A,C)), 
	implica((inclstr(A,B),inclstr(B,C)), inclstr(A,C)))))).

% varianta cu cele doua predicate separate
ex21 :- not((triplet(A,B,C), not(implica((implica(A,B), inclstr(B,C)), inclstr(A,C))))).
ex22 :- not((triplet(A,B,C), not(implica((inclstr(A,B),inclstr(B,C)), inclstr(A,C))))).

%>>>>>>>>> EXERCITIUL 3
% (A<=B) => ((AUC<=BUC) si (A^C<=B^C) si (A\C<=B\C))

ex3 :- not((triplet(A,B,C), not(implica(implica(A,B), (implica(A;C, B;C), 
	implica((A,C),(B,C)), implica((A,not(C)), (B,not(C)))))))).

%>>>>>>>>> EXERCITIUL 4
% ((A<=B) si (C<=D)) => ((AUC<=BUD) si (A^C<=B^D) si (A\D<=B\C))

ex4 :- not((cvadruplet(A,B,C,D), not(implica((implica(A,B),implica(C,D)), 
	(implica((A;C),(B;D)), implica((A,C),(B,D)), implica((A,not(D)),(B,not(C)))))))).

%>>>>>>>>> EXERCITIUL 5
% ((A<=B) si (A<=C)) <=> (A<=B^C)

ex5 :- not((triplet(A,B,C), not(echiv((implica(A,B), implica(A,C)), implica(A,(B,C)))))).

%>>>>>>>>> EXERCITIUL 6
% (A^(B\A)) = fals

ex6 :- not((pereche(A,B), not(echiv((A,B,not(A)),false)))).

%>>>>>>>>> EXERCITIUL 7
% (A\B = A\(A^B)) si (A/\B = (AUB)\(A^B)) 

ex7 :- not((pereche(A,B), not((echiv((A,not(B)),(A,not((A,B)))), echiv(A xor B,((A;B),not((A,B)))))))).

% varianta cu cele doua proprietati separate:
ex71 :- not((pereche(A,B), not(echiv((A,not(B)),(A,not((A,B))))))).
ex72 :- not((pereche(A,B), not(echiv(A xor B,((A;B),not((A,B))))))).

%>>>>>>>>> EXERCITIUL 8
% (A^B = fals) <=> (B\A = B)

ex8 :- not((pereche(A,B), not(echiv(echiv((A,B),false), echiv((B,not(A)),B))))).

%>>>>>>>>> EXERCITIUL 9
% -(A^B) = (-A)U(-B)

% cu t avand o valoare booleana arbitrara:
ex9arbitrar :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv((T,not((A,B))), ((T,not(A)); (T,not(B))))))).

% cu t presupusa adevarata:
ex9adev :- not((pereche(A,B), not(echiv(not((A,B)),(not(A);not(B)))))).

%>>>>>>>>> EXERCITIUL 10
% (A<B) <=> (-B<-A)

% cu t avand o valoare booleana arbitrara:
ex10arbitrar :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv(inclstr(A,B), 
	inclstr((T,not(B)),(T,not(A))))))).

% cu t presupusa adevarata:
ex10adev :- not((pereche(A,B), not(echiv(inclstr(A,B),inclstr(not(B),not(A)))))).

%>>>>>>>>> EXERCITIUL 11
% (A^B=fals) <=> (B<=-A)

% cu t avand o valoare booleana arbitrara:
ex11arbitrar :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv(echiv((A,B),false), implica(B,(T,not(A))))))).

% cu t presupusa adevarata:
ex11adev :- not((pereche(A,B), not(echiv(echiv((A,B),false),implica(B,not(A)))))).

%>>>>>>>>> EXERCITIUL 12
% (AUB=T) <=> (-B<=A) <=> (-A<=B)

% cu t avand o valoare booleana arbitrara:
ex12arbitrar1 :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv(echiv((A;B),T), implica((T,not(B)),A))))).
ex12arbitrar2 :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv(implica((T,not(B)),A), 
	implica((T,not(A)),B))))).

% cu t presupusa adevarata:
ex12adev1 :- not((pereche(A,B), not(echiv(echiv((A;B),true),implica(not(B),A))))).
ex12adev2 :- not((pereche(A,B), not(echiv(implica(not(B),A),implica(not(A),B))))).

%>>>>>>>>> EXERCITIUL 13
% ((AUB=T) si (A^B=fals)) <=> (A=-B) <=> (B=-A)

% cu t avand o valoare booleana arbitrara:
ex13arbitrar1 :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv(((echiv(A;B,T)),(echiv((A,B),false))), 
	echiv(A,(T,not(B))))))).
ex13arbitrar2 :- not((triplet(A,B,T), implica(A,T), implica(B,T), not(echiv(echiv(A,(T,not(B))), 
	echiv(B,(T,not(A))))))).

% cu t presupusa adevarata:
ex13adev1 :- not((pereche(A,B), not(echiv((echiv(A;B,true),echiv((A,B),false)),echiv(A,not(B)))))).
ex13adev2 :- not((pereche(A,B), not(echiv(echiv(A,not(B)),echiv(B,not(A)))))).