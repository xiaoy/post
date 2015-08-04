#include <stdio.h>

typedef unsigned int uint32_t;
uint32_t TEA_KEY[4] = {0x95a2334c, 0x89235467, 0xb3cde2dd, 0x98a2b4d5};

void encrypt(uint32_t* v, uint32_t* k);
void decrypt(uint32_t* v, uint32_t* k);

void str_encrypt(unsigned char* buff);
void str_decrypt(unsigned char* buff);

int main(int argc, char** argv){
    FILE* fpin, *fpout;
    unsigned char buff[9], buffin[9], buffout[9];
    int byte_count = 0;

    if(argc < 3){
        printf("Use: %s [filename input] [filename output]\n", argv[0]);
        return 0;
    }

    if((fpin = fopen(argv[1], "rb")) == NULL){
        printf("Problem opening input file %s.\n", argv[1]);
        return 0;
    }

    if((fpout = fopen(argv[2], "wb")) == NULL){
        printf("Problem opening output file %s.\n", argv[2]);
        return 0;
    }

    int i;
    while(fread(buff, 1, 8, fpin) == 8){
        if(argc > 3){
            for(i = 0; i < 8; ++i){
                buffin[i] = buff[i];
            }
            str_encrypt(buff);

            for(i = 0; i < 8; ++i){
                buffout[i] = buff[i];
            }
            str_decrypt(buffout);

            for(i = 0; i < 8; ++i){
                if(buffin[i] != buffout[i]){
                    printf("decode test failed\n");
                }
            }
        }else{
            str_decrypt(buff);
        }
        fwrite(buff, 1, 8, fpout);
        byte_count += 8;
    }

    if(!feof(fpin)){
        printf("unexpected input file error encountered.\n");
    }

    printf("%s complete %i bytes total.\n", (argc > 3 ? "Encrypt" : "Decrypt"), byte_count);

    fclose(fpin);
    fclose(fpout);

    return 0;
}

void str_encrypt(unsigned char* buff){
    uint32_t block[2];

    block[0] = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | buff[3];
    block[1] = (buff[4] << 24) | (buff[5] << 16) | (buff[6] << 8) | buff[7];

    encrypt(block, TEA_KEY);

    buff[0] = (char)((block[0] >> 24) & 0xff);
    buff[1] = (char)((block[0] >> 16) & 0xff);
    buff[2] = (char)((block[0] >> 8) & 0xff);
    buff[3] = (char)((block[0]) & 0xff);
    buff[4] = (char)((block[1] >> 24) & 0xff);
    buff[5] = (char)((block[1] >> 16) & 0xff);
    buff[6] = (char)((block[1] >> 8) & 0xff);
    buff[7] = (char)((block[1]) & 0xff);
}

void str_decrypt(unsigned char* buff){
    uint32_t block[2];
    block[0] = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | buff[3];
    block[1] = (buff[4] << 24) | (buff[5] << 16) | (buff[6] << 8) | buff[7];

    decrypt(block, TEA_KEY);

    buff[0] = (char)((block[0] >> 24) & 0xff);
    buff[1] = (char)((block[0] >> 16) & 0xff);
    buff[2] = (char)((block[0] >> 8) & 0xff);
    buff[3] = (char)((block[0]) & 0xff);
    buff[4] = (char)((block[1] >> 24) & 0xff);
    buff[5] = (char)((block[1] >> 16) & 0xff);
    buff[6] = (char)((block[1] >> 8) & 0xff);
    buff[7] = (char)((block[1]) & 0xff);
}



void encrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0, i;           /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i < 32; i++) {                       /* basic cycle start */
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}

void decrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;  /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i<32; i++) {                         /* basic cycle start */
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}
