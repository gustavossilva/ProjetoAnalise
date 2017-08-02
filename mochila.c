void mochila(int quantidades[], int valores[],int n){
	int P = 50;
	int N = n;
	float valores_unitarios[N];
	int itensId[N];
	float porcentagemAdicionada[N];
	int peso = 0;
	float valorMochila = 0;
	
	quantidades[0] = 20;
	valores[0] = 60;
	quantidades[1] = 10;
	valores[1] = 100;
	quantidades[2] = 30;
	valores[2] = 120;
	
	int i;
	for(i = 0; i < N; i++){
		itensId[i] = i;
		porcentagemAdicionada[i] = 0.0;
		valores_unitarios[i] = valores[i] / quantidades[i];
	}
	// ordenar por valor unitario
	int key, keyId, j;
   	for (i = 1; i < N; i++){
        key = valores_unitarios[i];
        keyId = itensId[i];
        j = i-1;
 
        while (j >= 0 && valores_unitarios[j] > key){
            valores_unitarios[j+1] = valores_unitarios[j];
            itensId[j+1] = itensId[j];
            j = j-1;
        }
    	valores_unitarios[j+1] = key;
        itensId[j+1] = keyId;
   	}

	i = N-1;
	peso = 0;
	valorMochila = 0;
	int cabe;
	float porcentagem;
	while(peso <= P && i >= 0){
		if(peso + quantidades[itensId[i]] > P){
			cabe = P - peso;
			porcentagem = (float)cabe / (float)quantidades[itensId[i]];
			//printf("Porcentagem : %lf\n", porcentagem);
			porcentagemAdicionada[itensId[i]] = porcentagem;
			peso += cabe;
			valorMochila += valores[itensId[i]] * cabe;
			//printf("Adicionado item %d com quantidade %d\n", itensId[i], cabe);		
		}
		else{
			porcentagemAdicionada[itensId[i]] = 1;
			peso += quantidades[itensId[i]];
			valorMochila += valores[itensId[i]];
			//printf("Adicionado item %d com quantidade %d\n", itensId[i], quantidades[itensId[i]]);	
		}
		i--;	
	}
}
