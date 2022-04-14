#include <stdlib.h>




float vorbelegenPatient(struct patient p[], int length){
    float erg = 0;
    for (int i = 0; i< length; i++){
        p[i].alter = i;
        erg = erg + p[i].alter;
    }return erg / length;
}
int main(){


}
