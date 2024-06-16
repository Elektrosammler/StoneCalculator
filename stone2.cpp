#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <fstream>
#include <iterator>
#include <list> 
int addstone(short** field, int x, int y, double* steingroesse) {
    std::cout;
    int count2 = 0;
    for (int i = 0; i < 4 * steingroesse[0]; i++) {
        for (int j = 0; j < 4 * steingroesse[1]; j++) {
            if (((j + y >= 0)&&(i + x >= 0) &&( x + i < 40000) && (y + j < 40000)) && (field[x + i][y + j] == 2)) {
                field[x + i][y + j] = 3;
                count2++;
            }
        }
    }
    return count2;
}
int reversaddstone(short** field, int x, int y,double* steingroesse) {
    int count2 = 0;
    for (int i = 0; i < 4 * steingroesse[1]; i++) {
        for (int j = 0; j < 4 * steingroesse[0]; j++) {
            if (((j + y >= 0) && (i + x >= 0) && (x + i < 40000) && (y + j < 40000)) && (field[x + i][y + j] == 2)) {
                field[x + i][y + j] = 3;
                count2++;
            }
        }
    }
    return count2;
}
void addlist3(std::list<int> lxy, int x, int y, int direction) {
    lxy.push_front(direction);
    lxy.push_front(y);
    lxy.push_front(x);
}
void removelist3(std::list<int> lxy) {
    for (int i = 0; i <3; i++) {
        lxy.pop_front();
    }
}
int** arrayadd(int** array, int pos,int x, int y, int direction) {
    bool changed = 0;
    if (array[1][0] < pos) {
        changed = 1;
        int** array2 = (int**)malloc(sizeof(int*) * (2 + array[1][0]) * 2);
        for (int i = 0; i < array[1][0] + 2; i++) {
            array2[i] == array[i];
        }
        array2[0][0] = array[0][0] + 1;
        array2[0][1] = array[1][0] * 2;
        for (int i = array2[0][0] - 1; i < array2[1][0]; i++) {
            array[i] = (int*)malloc(sizeof(int) * 3);
        }
        array2[pos][0] = x;
        array2[pos][1] = y;
        array2[pos][2] = direction;
        return array2;
    }
    else {
        if (0 < array[0][0] - pos) {
            array[0][0] = array[0][0] - pos;
        }
        array[pos][0] = x;
        array[pos][1] = y;
        array[pos][2] = direction;
    }
    return array;
    
    

}
int** getstorechecked() {
    int** storechecked = (int**)malloc(sizeof(int*) * 102 ) ;
    for (int i = 0; i < 2; i++) {
        storechecked[i] = (int*)malloc(sizeof(int));
    }
    for (int i = 2; i < 102; i++) {
        storechecked[i] = (int*)malloc(sizeof(int)*3);
    }
    storechecked[0][0] = 0;
    storechecked[1][0] = 100;
    return storechecked;
}
int finsidetwo(short** field) {
    bool on ;
    int counttwo = 0;
    for (int i = 0; i < 40000; i++) {
        on = 0;
        for (int j = 0; j < 4000; j++) {
            if (field[i][j] == 1) {
                on = on + 1;
            }
            if (on == 1){
                field[i][j] = 2;
                counttwo++;
            }
        }
    }
    return counttwo;
}
void getvallist(std::list<int> g, int* returnxy)
{
    std::list<int>::iterator it;
    it = g.begin();
    for (int i = 0; i < 3; i++) {
        returnxy[i] = *it;
        ++it;
    }
}
void mlines(short** field,int** storenames,short** storelines, double tmp, short direct, int i) {
    int zp;
    for (int j = 0; tmp * j <= storenames[i][1] * 4; j++) {
        zp = round((tmp * j));
        field[zp + storelines[i][0]][storelines[i][1] + (j * direct)] = 1;
    }
}
void calcangles(int** storenames) {
    int usednames = 0;
    while (storenames[usednames][0] == 1) {
        //std::cout << "usednames: " << usednames << "\n";
        usednames++;
    }
    //std::cout << "\n" << usednames << "\n";
    int* a = (int*)malloc(4*25);
    for (int i = 0; i < usednames; i++) {                       
        a[i] = storenames[i][2];
    }
    for (int i = 0; i < usednames - 1; i++) {
        for (int j = 1; i + j < usednames; j++) {
            a[i + j] = a[i] + a[i + j];
        }
    }
    for (int i = 0; i < usednames - 1; i++) {
        while (a[i] >= 360) {
            a[i] = a[i] - 360;
        }
    }
    for (int i = 0; i < usednames - 1; i++) {
        storenames[i][5] = a[i];
    }
    free(a);
}
short** ffield() {
    short** field = (short**)malloc(sizeof(short*) * 4 * 100 * 100);
    for (int i = 0; i < 40000; i++) {
        field[i] = (short*)malloc(sizeof(short) * 4 * 100 * 100);
    }
    for (int i = 0; i < 40000; i++) {
        for (int j = 0; j < 40000; j++) {
            field[i][j] = 0;
        }
    }
    return field;
}
short** mstorelines(int** storenames) {
    
    short** storelines = (short**)malloc(sizeof(short*)*26);
    for (int i = 0; i < 26; i++) {
        storelines[i] = (short*)malloc(sizeof(short) * 2);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 2; j++) {
            storelines[i][j] = 0;
        }
    }
    return storelines;

}
int** storenames1() {
    int** storenames = (int**)malloc(sizeof(int*) * (25+3));
    for (int i = 25; i < 28; i++) {
        storenames[i] = (int*)malloc(sizeof(int));
        storenames[i][0] = 0;
    }
    for (int i = 0; i < 25; i++) {
        storenames[i] = (int*)malloc(sizeof(int) * 6);
        //std::cout << "Allocated Storenemas: " << i <<  "   pointer == " << storenames[i] <<   "\n";
    }
    //std::cout << "storenames pointer: " << storenames << "\n";
    for (int k = 0; k < 25; k++) {
        for (int l = 0; l < 6; l++) {
            storenames[k][l] = 0;
        }
    }
    return storenames;
}
void fexit(bool* end) {
    *end = 1;
}
void fadd(int** storenames) {
    int pos;
    std::cin >> pos;
    storenames[pos - 1][0] = 1;
    std::string inp;
    for (int i = 0; i < 2; i++) {
        std::cin >> inp;
        if (inp == "angle") {
            std::cin >> storenames[pos - 1][2];
        }
        else if (inp == "lenght") {
            std::cin >> storenames[pos - 1][1];
        }
    }


}
void makefigure(short** field, int** storenames, short** storelines) {
    int count = 0;
    double tmp;
    short direct;
    
    while ((storenames[count + 1][0] == 1)&&(count + 1 < 25)) count++;
    storelines[0][0] = 400 * 75;
    storelines[0][1] = 400 * 50;
    for (int i = 0; i <= count; i++) {
        tmp = tan(180 - storenames[i][2] * (3.141592654 / 180));
        if ((storenames[i][2] < 90) || (storenames[i][2] > 270)) {
            direct = 1;
            mlines(field,storenames,storelines,tmp,direct,i);
        }
        else if (((storenames[i][2] > 90) && (storenames[i][2] < 270))) {
            direct = -1;
            mlines(field, storenames, storelines, tmp, direct, i);
        }
        else if ((storenames[i][2] == 90)) {
            for (int j = 0; (j <= storenames[i][1] * 4); j++) {
                field[storelines[i][0] + j][storenames[i][1]] = 1;
            }
        }
        else if (storenames[i][2] == 270) {
            for (int j = 0; (j <= storenames[i][1] * 4); j++) {
                field[storelines[i][0] - j][storenames[i][1]] = 1;
            }
        }
    }

}
bool fcheckstorechecked(int** storechecked,int x,int y) {
    for (int i = 0; i < storechecked[1][0];i++) {
        if ((storechecked[i][0] == x) && (storechecked[i][1] == y)) {
            return 1;
        }
    }
    return 0;
}
int freihenverband(short** field,std::list<int> lxy,double* steingroesse, int posiblestonefield, int* returnxy,short** storelines) {
    int** storechecked = getstorechecked();
    int stones = 0;
    int zp;
    for (int i = 0; (posiblestonefield > 0)&&(i +2 <= 40000); i++) {
        getvallist(lxy, returnxy);
        removelist3(lxy);
        zp = addstone(field, returnxy[0], returnxy[1],steingroesse);
        storechecked[i][0] = returnxy[0];
        storechecked[i][1] = returnxy[1];
        if (zp > 0) {
            stones++;
            posiblestonefield = posiblestonefield - zp;
        }
        if ((storechecked[i + 2][0] + steingroesse[0] * (i + 1) <= 40000) &&(storechecked[i + 2][1] + steingroesse[1] * (i + 1) <= 40000)&&(fcheckstorechecked(storechecked, storechecked[i + 2][0] + steingroesse[0] * (i + 1), storechecked[i + 2][1] + steingroesse[1] * (i + 1))==0 )) {
            addlist3(lxy, storechecked[i+2][0] + steingroesse[0] * (i + 1), storechecked[i + 2][1] + steingroesse[1] * (i + 1), 0);
        }
        if ((storechecked[i + 2][0] - steingroesse[0] * (i + 1) >= 0) && (storechecked[i + 2][1] + steingroesse[1] * (i + 1) <= 40000) && (fcheckstorechecked(storechecked, storechecked[i + 2][0] - steingroesse[0] * (i + 1), storechecked[i + 2][1] + steingroesse[1] * (i + 1)) == 0)) {
            addlist3(lxy, storechecked[i + 2][0] - steingroesse[0] * (i + 1), storechecked[i + 2][1] + steingroesse[1] * (i + 1), 0);
        }
        if ((storechecked[i + 2][0] + steingroesse[0] * (i + 1) <= 40000) && (storechecked[i + 2][1] - steingroesse[1] * (i + 1) >= 0) && (fcheckstorechecked(storechecked, storechecked[i + 2][0] + steingroesse[0] * (i + 1), storechecked[i + 2][1] - steingroesse[1] * (i + 1)) == 0)) {
            addlist3(lxy, storechecked[i + 2][0] + steingroesse[0] * (i + 1), storechecked[i + 2][1] - steingroesse[1] * (i + 1), 0);
        }
        if ((storechecked[i + 2][0] - steingroesse[0] * (i + 1) >= 0) && (storechecked[i + 2][1] - steingroesse[1] * (i + 1) >= 0) && (fcheckstorechecked(storechecked, storechecked[i + 2][0] - steingroesse[0] * (i + 1), storechecked[i + 2][1] - steingroesse[1] * (i + 1)) == 0)) {
            addlist3(lxy, storechecked[i + 2][0] - steingroesse[0] * (i + 1), storechecked[i + 2][1] - steingroesse[1] * (i + 1), 0);
        }
    }
    return stones;
}
int frechteckverband(short** field, std::list<int> lxy, double* steingroesse, int posiblestonefield, int* returnxy, short** storelines) {
    int** storechecked = getstorechecked();
    int stones = 0;
    int zp;
    bool direct;
    int y;
    int x;
    for (int i = 0; posiblestonefield > 0; i++) {
        getvallist(lxy, returnxy);
        removelist3(lxy);
        if (returnxy[2] == 0) {
            zp = addstone(field, returnxy[0], returnxy[1], steingroesse);
            direct = 0;
        }
        else{
            zp = addstone(field, returnxy[0], returnxy[1], steingroesse);
            direct = 1;
        }
        storechecked[i][0] = returnxy[0];
        storechecked[i][1] = returnxy[1];
        storechecked[i][2] = returnxy[2];
        if (zp > 0) {
            stones++;
            posiblestonefield = posiblestonefield - zp;
        }
        if (direct == 0) {
            x = returnxy[0] - steingroesse[1]  ;
            y = returnxy[1];
            direct = 1;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0]-steingroesse[1]+steingroesse[0];
            y = returnxy[1]-steingroesse[1];
            direct = 1;
            if (((x <= 40000)&&( x >= 0)) && ((y <= 4000)&&(y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] - steingroesse[0];
            y = returnxy[1] + steingroesse[0];
            direct = 0;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0];
            y = returnxy[1] + steingroesse[1];
            direct = 1;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] + steingroesse[0];
            y = returnxy[1] + steingroesse[1]- steingroesse[0];
            direct = 1;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] + steingroesse[1] ;
            y = returnxy[1] - steingroesse[1];
            direct = 0;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
        }
        else {
            x = returnxy[0];
            y = returnxy[1] - steingroesse[1];
            direct = 0;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] + steingroesse[1]- steingroesse[0];
            y = returnxy[1] + steingroesse[0];
            direct = 0;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] + steingroesse[0];
            y = returnxy[1] - steingroesse[0];
            direct = 1;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] + steingroesse[1];
            y = returnxy[1];
            direct = 0;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] - steingroesse[0];
            y = returnxy[1] - steingroesse[0];
            direct = 1;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
            x = returnxy[0] + steingroesse[0];
            y = returnxy[1] - steingroesse[1]+ steingroesse[0];
            direct = 0;
            if (((x <= 40000) && (x >= 0)) && ((y <= 4000) && (y >= 0)) && fcheckstorechecked(storechecked, x, y)) {
                addlist3(lxy, x, y, direct);
            }
        }
    }
    return stones;
}
int countstones(short** field, int** storenames, short** storelines,double* steingroesse ) {
    int** storechecks = (int**)malloc(sizeof(int*)*30);
    int* returnxy = (int*)malloc(sizeof(int) * 3);
    int zp;
    std::list<int> lxy;
    int posiblestonefield = finsidetwo(field);
    for (int i = 0; i < 25; i++) {
        storechecks[i] = (int*)malloc(sizeof(int) * 3);
    }
    lxy.push_front(storelines[0][0]);
    lxy.push_front(storelines[0][1]);
    lxy.push_front(0);
    if(storenames[27][0] == 1) {
        zp = frechteckverband(field, lxy, steingroesse, posiblestonefield, returnxy, storelines);
        return zp;
    }
    else if (storenames[27][0] == 2) {
        zp = freihenverband(field,lxy,steingroesse, posiblestonefield, returnxy, storelines); 
        return zp;
    }
 }
void fparallel(int** storenames) {
    int inp1;
    int inp2;
    int inp3;
    std::cin >> inp1;
    std::cin >> inp2;
    storenames[inp1 - 1][3] = inp2;
    storenames[inp2 - 1][3] = inp1;
    std::string inp;
    std::cin >> inp;
    if (inp == "distance") {
        std::cin >> inp3;
        storenames[inp1 - 1][4] = inp3;
        storenames[inp2 - 1][4] = inp3;
    }
}
int fcalculate(int** storenames, double* steingroesse) {
    //std::cout << "1";

    steingroesse[0] = steingroesse[0] * 4;
    steingroesse[1] = steingroesse[1] * 4;
    int stones;
    short** field = ffield();
    short** storelines = mstorelines(storenames);
    //std::cout << "1.5";
    calcangles(storenames);
    //std::cout << "2";
    makefigure(field, storenames, storelines);
    stones = countstones(field, storenames, storelines, steingroesse);
    std::cout << "stones needed: " << stones <<  "\n";
    free(field);
    free(storelines);
    //std::cout << "4";
    return 0;
}
void faddbase(int** storenames) {
    std::cin >> storenames[26][0];
    storenames[26][0] = storenames[26][0] - 1;
}
void fsteingroesse(double* steingroesse) {
    std::cin >> steingroesse[0];
    std::cin;
    std::cin >> steingroesse[1];
}
void fverbund(int** storenames){

    std::string inp;
    std::cin >> inp;
    if (inp == "Rechteckverband") {
        storenames[27][0] = 1;
    }
    else if (inp == "Reihenverband"){
        storenames[27][0] = 2;
    }
}
int main() {
    int** storenames = storenames1();
    double* steingroesse = (double*)malloc(2 * sizeof(double));
    std::string inp;
    bool end = 0;
    bool* ptrend = &end;
    int counteradd = 0;
    bool dev = 1;
    if(dev == 1){
        for (int i = 0; i < 4; i++){
            storenames[i][0] = 1;
            storenames[i][1] = 25;
            storenames[i][2] = 90;
        }
        storenames[26][0] = 3;
        storenames[27][0] = 2;
        steingroesse[0] = 10;
        steingroesse[1] = 10;
        fcalculate(storenames,steingroesse);
        end = 1;
    }
    while (end == 0) {
        std::cin >> inp;
        if (inp == "exit") {
            std::cout << "";
            fexit(ptrend);
        }
        else if (inp == "add") {
            fadd(storenames);
        }
        else if (inp == "parallel") {
            fparallel(storenames);
        }
        else if (inp == "calculate") {
            fcalculate(storenames, steingroesse);
        }
        else if (inp == "addbase") {
            faddbase(storenames);
        }
        else if (inp == "verbund") {
            fsteingroesse(steingroesse);
        }
    }
    std::cout << "5";
    free(storenames);
    free(steingroesse);
    return 0;
}