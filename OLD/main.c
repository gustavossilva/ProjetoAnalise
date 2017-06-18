//gcc -o my_app main.c gerador.c algs.c -lm
//./my_app

#include "main.h"

/*gerarVetor(vetor,k,flag) Gera um vetor V alocado dinamicamento tamanho 2^k e com a ordenação baseado na flag
    flag 0 = vetor totalmente aleatorio
    flag 1 = Vetores ordenados em ordem crescente
    flag 2 = Vetores ordenados em ordem decrescente
    flag 3 = vetor 90% ordenado de forma crescente
    flag 4 = vetor 90% ordenado de forma decrescente
    flag 5 = vetor 50% ordenado de forma crescente
*/
int main() {
    //FILE *f = fopen("file.txt", "w");

    int i;
/*    Vetor *vtt;
    Vetor vt;*/
    Vetor *vv;
    Vetor v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12; //Aleatorios
    Vetor v13,v14,v15,v16,v17,v18,v19,v20,v21,v22,v23,v24; //Ordenado crescente
    Vetor v25,v26,v27,v28,v29,v30,v31,v32,v33,v34,v35,v36; //Ordenado decrescente
    Vetor v37,v38,v39,v40,v41,v42,v43,v44,v45,v46,v47,v48; //90% Ordenado crescente
    Vetor v49,v50,v51,v52,v53,v54,v55,v56,v57,v58,v59,v60; //90% Ordenado decrescente
    Vetor v61,v62,v63,v64,v65,v66,v67,v68,v69,v70,v71,v72; //80% Ordenado crescente
    Vetor v73,v74,v75,v76,v77,v78,v79,v80,v81,v82,v83,v84; //80% Ordenado decrescente
    Vetor v85,v86,v87,v88,v89,v90,v91,v92,v93,v94,v95,v96; //70% Ordenado crescente
    Vetor v97,v98,v99,v100,v101,v102,v103,v104,v105,v106,v107,v108; //70% Ordenado decrescente
    Vetor v109,v110,v111,v112,v113,v114,v115,v116,v117,v118,v119,v120; //60% Ordenado crescente
    Vetor v121,v122,v123,v124,v125,v126,v127,v128,v129,v130,v131,v132; //60% Ordenado decrescente
    Vetor v133,v134,v135,v136,v137,v138,v139,v140,v141,v142,v143,v144; //50% Ordenado crescente
    Vetor v145,v146,v147,v148,v149,v150,v151,v152,v153,v154,v155,v156; //50% Ordenado decrescente
    time_t tempo_ini,tempo_fim;
    float tempo_med;
    //O que altera na geração é a flag enviada
    /*Após gerar, executa 3x o vetor peagndo o tempo tipo
     * tempo_ini ordenada tempo_fim (3x) mediana dos 3 valores
     * Isso deve ser feito para todos os vetores, pois com o mesmo vetor o tempo pode variar
     * usando o mesmo algoritmo
     * */
    //Vetores Aleatorios
    v1 = gerarVetor(v1,3,0);
/*    vt.v = v1;
    vt.size = 8;
    vtt = (Vetor*)malloc(157*sizeof(Vetor));
    vtt[0] = vt;*/
    v2 = gerarVetor(v2,4,0);
    v3 = gerarVetor(v3,5,0);
    v4 = gerarVetor(v4,6,0);
    v5 = gerarVetor(v5,7,0);
    v6 = gerarVetor(v6,8,0);
    v7 = gerarVetor(v7,9,0);
    v8 = gerarVetor(v8,10,0);
    v9 = gerarVetor(v9,11,0);
    v10 = gerarVetor(v10,12,0);
    v11 = gerarVetor(v11,13,0);
    v12 = gerarVetor(v12,14,0);
    //Vetores ordenados 100% crescente
    v13 = gerarVetor(v13,3,1);
    v14 = gerarVetor(v14,4,1);
    v15 = gerarVetor(v15,5,1);
    v16 = gerarVetor(v16,6,1);
    v17 = gerarVetor(v17,7,1);
    v18 = gerarVetor(v18,8,1);
    v19 = gerarVetor(v19,9,1);
    v20 = gerarVetor(v20,10,1);
    v21 = gerarVetor(v21,11,1);
    v22 = gerarVetor(v22,12,1);
    v23 = gerarVetor(v23,13,1);
    v24 = gerarVetor(v24,14,1);
    //Vetores ordenados 100% decrescente
    v25 = gerarVetor(v25,3,2);
    v26 = gerarVetor(v26,4,2);
    v27 = gerarVetor(v27,5,2);
    v28 = gerarVetor(v28,6,2);
    v29 = gerarVetor(v29,7,2);
    v30 = gerarVetor(v30,8,2);
    v31 = gerarVetor(v31,9,2);
    v32 = gerarVetor(v32,10,2);
    v33 = gerarVetor(v33,11,2);
    v34 = gerarVetor(v34,12,2);
    v35 = gerarVetor(v35,13,2);
    v36 = gerarVetor(v36,14,2);
    //Vetores ordenados 90% crescente
    v37 = gerarVetor(v37,3,3);
    v38 = gerarVetor(v38,4,3);
    v39 = gerarVetor(v39,5,3);
    v40 = gerarVetor(v40,6,3);
    v41 = gerarVetor(v41,7,3);
    v42 = gerarVetor(v42,8,3);
    v43 = gerarVetor(v43,9,3);
    v44 = gerarVetor(v44,10,3);
    v45 = gerarVetor(v45,11,3);
    v46 = gerarVetor(v46,12,3);
    v47 = gerarVetor(v47,13,3);
    v48 = gerarVetor(v48,14,3);
    //Vetores ordenados 90% decrescente
    v49 = gerarVetor(v49,3,4);
    v50 = gerarVetor(v50,4,4);
    v51 = gerarVetor(v51,5,4);
    v52 = gerarVetor(v52,6,4);
    v53 = gerarVetor(v53,7,4);
    v54 = gerarVetor(v54,8,4);
    v55 = gerarVetor(v55,9,4);
    v56 = gerarVetor(v56,10,4);
    v57 = gerarVetor(v57,11,4);
    v58 = gerarVetor(v58,12,4);
    v59 = gerarVetor(v59,13,4);
    v60 = gerarVetor(v60,14,4);
    //Vetores ordenados 80% crescente
    v61 = gerarVetor(v61,3,5);
    v62 = gerarVetor(v62,4,5);
    v63 = gerarVetor(v63,5,5);
    v64 = gerarVetor(v64,6,5);
    v65 = gerarVetor(v65,7,5);
    v66 = gerarVetor(v66,8,5);
    v67 = gerarVetor(v67,9,5);
    v68 = gerarVetor(v68,10,5);
    v69 = gerarVetor(v69,11,5);
    v70 = gerarVetor(v70,12,5);
    v71 = gerarVetor(v71,13,5);
    v72 = gerarVetor(v72,14,5);
    //Vetores ordenados 80% decrescente
    v73 = gerarVetor(v73,3,6);
    v74 = gerarVetor(v74,4,6);
    v75 = gerarVetor(v75,5,6);
    v76 = gerarVetor(v76,6,6);
    v77 = gerarVetor(v77,7,6);
    v78 = gerarVetor(v78,8,6);
    v79 = gerarVetor(v79,9,6);
    v80 = gerarVetor(v80,10,6);
    v81 = gerarVetor(v81,11,6);
    v82 = gerarVetor(v82,12,6);
    v83 = gerarVetor(v83,13,6);
    v84 = gerarVetor(v84,14,6);
    //Vetores ordenados 70% crescente
    v85 = gerarVetor(v85,3,7);
    v86 = gerarVetor(v86,4,7);
    v87 = gerarVetor(v87,5,7);
    v88 = gerarVetor(v88,6,7);
    v89 = gerarVetor(v89,7,7);
    v90 = gerarVetor(v90,8,7);
    v91 = gerarVetor(v91,9,7);
    v92 = gerarVetor(v92,10,7);
    v93 = gerarVetor(v93,11,7);
    v94 = gerarVetor(v94,12,7);
    v95 = gerarVetor(v95,13,7);
    v96 = gerarVetor(v96,14,7);
    //Vetores ordenados 70% decrescente
    v97 = gerarVetor(v97,3,8);
    v98 = gerarVetor(v98,4,8);
    v99 = gerarVetor(v99,5,8);
    v100 = gerarVetor(v100,6,8);
    v101 = gerarVetor(v101,7,8);
    v102 = gerarVetor(v102,8,8);
    v103 = gerarVetor(v103,9,8);
    v104 = gerarVetor(v104,10,8);
    v105 = gerarVetor(v105,11,8);
    v106 = gerarVetor(v106,12,8);
    v107 = gerarVetor(v107,13,8);
    v108 = gerarVetor(v108,14,8);
    //Vetores ordenados 60% crescente
    v109 = gerarVetor(v109,3,9);
    v110 = gerarVetor(v110,4,9);
    v111 = gerarVetor(v111,5,9);
    v112 = gerarVetor(v112,6,9);
    v113 = gerarVetor(v113,7,9);
    v114 = gerarVetor(v114,8,9);
    v115 = gerarVetor(v115,9,9);
    v116 = gerarVetor(v116,10,9);
    v117 = gerarVetor(v117,11,9);
    v118 = gerarVetor(v118,12,9);
    v119 = gerarVetor(v119,13,9);
    v120 = gerarVetor(v120,14,9);
    //Vetores ordenados 60% decrescente
    v121 = gerarVetor(v121,3,10);
    v122 = gerarVetor(v122,4,10);
    v123 = gerarVetor(v123,5,10);
    v124 = gerarVetor(v124,6,10);
    v125 = gerarVetor(v125,7,10);
    v126 = gerarVetor(v126,8,10);
    v127 = gerarVetor(v127,9,10);
    v128 = gerarVetor(v128,10,10);
    v129 = gerarVetor(v129,11,10);
    v130 = gerarVetor(v130,12,10);
    v131 = gerarVetor(v131,13,10);
    v132 = gerarVetor(v132,14,10);
    //Vetores ordenados 50% decrescente
    v133 = gerarVetor(v133,3,11);
    v134 = gerarVetor(v134,4,11);
    v135 = gerarVetor(v135,5,11);
    v136 = gerarVetor(v136,6,11);
    v137 = gerarVetor(v137,7,11);
    v138 = gerarVetor(v138,8,11);
    v139 = gerarVetor(v139,9,11);
    v140 = gerarVetor(v140,10,11);
    v141 = gerarVetor(v141,11,11);
    v142 = gerarVetor(v142,12,11);
    v143 = gerarVetor(v143,13,11);
    v144 = gerarVetor(v144,14,11);
    //Vetores ordenados 50% crescente
    v145 = gerarVetor(v145,3,12);
    v146 = gerarVetor(v146,4,12);
    v147 = gerarVetor(v147,5,12);
    v148 = gerarVetor(v148,6,12);
    v149 = gerarVetor(v149,7,12);
    v150 = gerarVetor(v150,8,12);
    v151 = gerarVetor(v151,9,12);
    v152 = gerarVetor(v152,10,12);
    v153 = gerarVetor(v153,11,12);
    v154 = gerarVetor(v154,12,12);
    v155 = gerarVetor(v155,13,12);
    v156 = gerarVetor(v156,14,12);


    vv = (Vetor*)malloc(157*sizeof(Vetor));
    vv[0] = v1;
    vv[1] = v2;
    vv[2] = v3;
    vv[3] = v4;
    vv[4] = v5;
    vv[5] = v6;
    vv[6] = v7;
    vv[7] = v8;
    vv[8] = v9;
    vv[9] = v10;
    vv[10] = v11;
    vv[11] = v12;
    vv[12] = v13;
    vv[13] = v14;
    vv[14] = v15;
    vv[15] = v16;
    vv[16] = v17;
    vv[17] = v18;
    vv[18] = v19;
    vv[19] = v20;
    vv[20] = v21;
    vv[21] = v22;
    vv[22] = v23;
    vv[23] = v24;
    vv[24] = v25;
    vv[25] = v26;
    vv[26] = v27;
    vv[27] = v28;
    vv[28] = v29;
    vv[29] = v30;
    vv[30] = v31;
    vv[31] = v32;
    vv[32] = v33;
    vv[33] = v34;
    vv[34] = v35;
    vv[35] = v36;
    vv[36] = v37;
    vv[37] = v38;
    vv[38] = v39;
    vv[39] = v40;
    vv[40] = v41;
    vv[41] = v42;
    vv[42] = v43;
    vv[43] = v44;
    vv[44] = v45;
    vv[45] = v46;
    vv[46] = v47;
    vv[47] = v48;
    vv[48] = v49;
    vv[49] = v50;
    vv[50] = v51;
    vv[51] = v52;
    vv[52] = v53;
    vv[53] = v54;
    vv[54] = v55;
    vv[55] = v56;
    vv[56] = v57;
    vv[57] = v58;
    vv[58] = v59;
    vv[59] = v60;
    vv[60] = v61;
    vv[61] = v62;
    vv[62] = v63;
    vv[63] = v64;
    vv[64] = v65;
    vv[65] = v66;
    vv[66] = v67;
    vv[67] = v68;
    vv[68] = v69;
    vv[69] = v70;
    vv[70] = v71;
    vv[71] = v72;
    vv[72] = v73;
    vv[73] = v74;
    vv[74] = v75;
    vv[75] = v76;
    vv[76] = v77;
    vv[77] = v78;
    vv[78] = v79;
    vv[79] = v80;
    vv[80] = v81;
    vv[81] = v82;
    vv[82] = v83;
    vv[83] = v84;
    vv[84] = v85;
    vv[85] = v86;
    vv[86] = v87;
    vv[87] = v88;
    vv[88] = v89;
    vv[89] = v90;
    vv[90] = v91;
    vv[91] = v92;
    vv[92] = v93;
    vv[93] = v94;
    vv[94] = v95;
    vv[95] = v96;
    vv[96] = v97;
    vv[97] = v98;
    vv[98] = v99;
    vv[99] = v100;
    vv[100] = v101;
    vv[101] = v102;
    vv[102] = v103;
    vv[103] = v104;
    vv[104] = v105;
    vv[105] = v106;
    vv[106] = v107;
    vv[107] = v108;
    vv[108] = v109;
    vv[109] = v110;
    vv[110] = v111;
    vv[111] = v112;
    vv[112] = v113;
    vv[113] = v114;
    vv[114] = v115;
    vv[115] = v116;
    vv[116] = v117;
    vv[117] = v118;
    vv[118] = v119;
    vv[119] = v120;
    vv[120] = v121;
    vv[121] = v122;
    vv[122] = v123;
    vv[123] = v124;
    vv[124] = v125;
    vv[125] = v126;
    vv[126] = v127;
    vv[127] = v128;
    vv[128] = v129;
    vv[129] = v130;
    vv[130] = v131;
    vv[131] = v132;
    vv[132] = v133;
    vv[133] = v134;
    vv[134] = v135;
    vv[135] = v136;
    vv[136] = v137;
    vv[137] = v138;
    vv[138] = v139;
    vv[139] = v140;
    vv[140] = v141;
    vv[141] = v142;
    vv[142] = v142;
    vv[143] = v144;
    vv[144] = v145;
    vv[145] = v146;
    vv[146] = v147;
    vv[147] = v148;
    vv[148] = v149;
    vv[149] = v150;
    vv[150] = v151;
    vv[151] = v152;
    vv[152] = v153;
    vv[153] = v154;
    vv[154] = v155;
    vv[155] = v156;

    //Vetores criados
    for(int i=0;i<156;i++){
        for(int j=0;j<3;j++){
            tempo_ini = time(NULL);
           quick(vv[i].v,0,vv[i].size);
            tempo_fim = time(NULL);
            tempo_med += difftime(tempo_ini,tempo_fim);
        }
        tempo_med = tempo_med/3;
        printf("Tempo para vetor[%d] : %f",i+1,tempo_med);
        //Printa o vetor i+1 (v1,v2,v3,v4,v5) e o tempo dele
        //Para saber qual tipo de vetor é, é só olhar pra cima nas definições das variaveis
        //int v1 //Aleatorios (v1 é 1 vetor aleatorio)
        //a quantidade de elementos está na função de geração
        //v1 = gerarVetor(v1,3,0); então é esse 3, logo v1 tem tamanho 2^3 (o segundo argumento é o K)
        tempo_med = 0;
    }
    //exibeVetor(vv[155].v,vv[155].size);
    //printf("Tamanho %d",vv[11].size);
    //exibeVetor(vv[0],8);
    //exibeVetor(vv[24],8);
    //exibeVetor(vv[155],16382);
    //printf("site of %ld",sizeof(*vv[155]));
    /*for(i =1;i<pow(2,14);i++){
        fprintf(f,"%d %d %f %f %f\n",1,i,log2(i),i*log2(i),pow(i,2));
    }*/
    /*TODO Pegar como calcula no C o tempo e calcular e depois testar o algoritmo (ordenar algum);
     * Conferir se está tudo correto com o tipo vetor
     * Colocar ordenação para retornar o vetor e não substitui-lo, para conseguimors fazer 3x a ordenação
     * */
    /*for(i =0;i<156;i++){
        free(vv[i].v);
    }
    //free(vv);
    */
    return 0;
}

