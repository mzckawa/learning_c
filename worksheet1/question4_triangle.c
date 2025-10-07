#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    char letra;

    scanf("%c", &letra);

    switch(letra){

        case 'A':
        printf("%c", 'A');
        break;

        case 'B':
        printf("%s", ".A.\nABA");
        break;

        case 'C':
        printf("%s", "..A..\n.ABA.\nABCBA");
        break;

        case 'D':
        printf("%s", "...A...\n..ABA..\n.ABCBA.\nABCDCBA");
        break;

        case 'E':
        printf("%s", "....A....\n...ABA...\n..ABCBA..\n.ABCDCBA.\nABCDEDCBA");
        break;

        case 'F':
        printf("%s", ".....A.....\n....ABA....\n...ABCBA...\n..ABCDCBA..\n.ABCDEDCBA.\nABCDEFEDCAB");
        break;

        case 'G':
        printf("%s", "......A......\n.....ABA.....\n....ABCBA....\n...ABCDCBA...\n..ABCDEDCBA..\n.ABCDEFEDCBA.\nABCDEFGFEDCBA");
        break;

        case 'H':
        printf("%s", ".......A.......\n......ABA......\n.....ABCBA.....\n....ABCDCBA....\n...ABCDEDCBA...\n..ABCDEFEDCBA..\n.ABCDEFGFEDCBA.\nABCDEFGHGFEDCBA");
        break;

        case 'I':
        printf("%s", "........A........\n.......ABA.......\n......ABCBA......\n.....ABCDCBA.....\n....ABCDEDCBA....\n...ABCDEFEDCBA...\n..ABCDEFGFEDCBA..\n.ABCDEFGHGFEDCBA.\nABCDEFGHIHGFEDCBA");
        break;

        case 'J':
        printf("%s", ".........A.........\n........ABA........\n.......ABCBA.......\n......ABCDCBA......\n.....ABCDEDCBA.....\n....ABCDEFEDCBA....\n...ABCDEFGFEDCBA...\n..ABCDEFGHGFEDCBA..\n.ABCDEFGHIHGFEDCBA.\nABCDEFGHIJIHGFEDCBA");
        break;

        case 'K':
        printf("%s", "..........A..........\n.........ABA.........\n........ABCBA........\n.......ABCDCBA.......\n......ABCDEDCBA......\n.....ABCDEFEDCBA.....\n....ABCDEFGFEDCBA....\n...ABCDEFGHGFEDCBA...\n..ABCDEFGHIHGFEDCBA..\n.ABCDEFGHIJIHGFEDCBA.\nABCDEFGHIJKJIHGFEDCBA");
        break;

        case 'L':
        printf("%s", "...........A...........\n..........ABA..........\n.........ABCBA.........\n........ABCDCBA........\n.......ABCDEDCBA.......\n......ABCDEFEDCBA......\n.....ABCDEFGFEDCBA.....\n....ABCDEFGHGFEDCBA....\n...ABCDEFGHIHGFEDCBA...\n..ABCDEFGHIJIHGFEDCBA..\n.ABCDEFGHIJKJIHGFEDCBA.\nABCDEFGHIJKLKJIHGFEDCBA");
        break;

        case 'M':
        printf("%s", "............A............\n...........ABA...........\n..........ABCBA..........\n.........ABCDCBA.........\n........ABCDEDCBA........\n.......ABCDEFEDCBA.......\n......ABCDEFGFEDCBA......\n.....ABCDEFGHGFEDCBA.....\n....ABCDEFGHIHGFEDCBA....\n...ABCDEFGHIJIHGFEDCBA...\n..ABCDEFGHIJKJIHGFEDCBA..\n.ABCDEFGHIJKLKJIHGFEDCBA.\nABCDEFGHIJKLMLKJIHGFECBA");
        break;

        case 'N':
        printf("%s", ".............A.............\n............ABA............\n...........ABCBA...........\n..........ABCDCBA..........\n.........ABCDEDCBA.........\n........ABCDEFEDCBA........\n.......ABCDEFGFEDCBA.......\n......ABCDEFGHGFEDCBA......\n.....ABCDEFGHIHGFEDCBA.....\n....ABCDEFGHIJIHGFEDCBA....\n...ABCDEFGHIJKJIHGFEDCBA...\n..ABCDEFGHIJKLKJIHGFEDCBA..\n.ABCDEFGHIJKLMLKJIHGFEDCBA.\nABCDEFGHIJKLMNMLKJIHGFEDCBA");
        break;

        case 'O':
        printf("%s", "..............A..............\n.............ABA.............\n............ABCBA............\n...........ABCDCBA...........\n..........ABCDEDCBA..........\n.........ABCDEFEDCBA.........\n........ABCDEFGFEDCBA........\n.......ABCDEFGHGFEDCBA.......\n......ABCDEFGHIHGFEDCBA......\n.....ABCDEFGHIJIHGFEDCBA.....\n....ABCDEFGHIJKJIHGFEDCBA....\n...ABCDEFGHIJKLKJIHGFEDCBA...\n..ABCDEFGHIJKLMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNMLKJIHGFEDCBA.\nABCDEFGHIJKLMNONMLKJIHGFEDCBA");
        break;

        case 'P':
        printf("%s", "...............A...............\n..............ABA..............\n.............ABCBA.............\n............ABCDCBA............\n...........ABCDEDCBA...........\n..........ABCDEFEDCBA..........\n.........ABCDEFGFEDCBA.........\n........ABCDEFGHGFEDCBA........\n.......ABCDEFGHIHGFEDCBA.......\n......ABCDEFGHIJIHGFEDCBA......\n.....ABCDEFGHIJKJIHGFEDCBA.....\n....ABCDEFGHIJKLKJIHGFEDCBA....\n...ABCDEFGHIJKLMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPONMLKJIHGFEDCBA");
        break;

        case 'Q':
        printf("%s", "................A................\n...............ABA...............\n..............ABCBA..............\n.............ABCDCBA.............\n............ABCDEDCBA............\n...........ABCDEFEDCBA...........\n..........ABCDEFGFEDCBA..........\n.........ABCDEFGHGFEDCBA.........\n........ABCDEFGHIHGFEDCBA........\n.......ABCDEFGHIJIHGFEDCBA.......\n......ABCDEFGHIJKJIHGFEDCBA......\n.....ABCDEFGHIJKLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA");
        break;

        case 'R':
        printf("%s", ".................A.................\n................ABA................\n...............ABCBA...............\n..............ABCDCBA..............\n.............ABCDEDCBA.............\n............ABCDEFEDCBA............\n...........ABCDEFGFEDCBA...........\n..........ABCDEFGHGFEDCBA..........\n.........ABCDEFGHIHGFEDCBA.........\n........ABCDEFGHIJIHGFEDCBA........\n.......ABCDEFGHIJKJIHGFEDCBA.......\n......ABCDEFGHIJKLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA");
        break;

        case 'S':
        printf("%s", "..................A..................\n.................ABA.................\n................ABCBA................\n...............ABCDCBA...............\n..............ABCDEDCBA..............\n.............ABCDEFEDCBA.............\n............ABCDEFGFEDCBA............\n...........ABCDEFGHGFEDCBA...........\n..........ABCDEFGHIHGFEDCBA..........\n.........ABCDEFGHIJIHGFEDCBA.........\n........ABCDEFGHIJKJIHGFEDCBA........\n.......ABCDEFGHIJKLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA");
        break;

        case 'T':
        printf("%s", "...................A...................\n..................ABA..................\n.................ABCBA.................\n................ABCDCBA................\n...............ABCDEDCBA...............\n..............ABCDEFEDCBA..............\n.............ABCDEFGFEDCBA.............\n............ABCDEFGHGFEDCBA............\n...........ABCDEFGHIHGFEDCBA...........\n..........ABCDEFGHIJIHGFEDCBA..........\n.........ABCDEFGHIJKJIHGFEDCBA.........\n........ABCDEFGHIJKLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA");
        break;

        case 'U':
        printf("%s", "....................A....................\n...................ABA...................\n..................ABCBA..................\n.................ABCDCBA.................\n................ABCDEDCBA................\n...............ABCDEFEDCBA...............\n..............ABCDEFGFEDCBA..............\n.............ABCDEFGHGFEDCBA.............\n............ABCDEFGHIHGFEDCBA............\n...........ABCDEFGHIJIHGFEDCBA...........\n..........ABCDEFGHIJKJIHGFEDCBA..........\n.........ABCDEFGHIJKLKJIHGFEDCBA.........\n........ABCDEFGHIJKLMLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMNMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNONMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA");
        break;

        case 'V':
        printf("%s", ".....................A.....................\n....................ABA....................\n...................ABCBA...................\n..................ABCDCBA..................\n.................ABCDEDCBA.................\n................ABCDEFEDCBA................\n...............ABCDEFGFEDCBA...............\n..............ABCDEFGHGFEDCBA..............\n.............ABCDEFGHIHGFEDCBA.............\n............ABCDEFGHIJIHGFEDCBA............\n...........ABCDEFGHIJKJIHGFEDCBA...........\n..........ABCDEFGHIJKLKJIHGFEDCBA..........\n.........ABCDEFGHIJKLMLKJIHGFEDCBA.........\n........ABCDEFGHIJKLMNMLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMNONMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDBCA");
        break;

        case 'W':
        printf("%s", "......................A......................\n.....................ABA.....................\n....................ABCBA....................\n...................ABCDCBA...................\n..................ABCDEDCBA..................\n.................ABCDEFEDCBA.................\n................ABCDEFGFEDCBA................\n...............ABCDEFGHGFEDCBA...............\n..............ABCDEFGHIHGFEDCBA..............\n.............ABCDEFGHIJIHGFEDCBA.............\n............ABCDEFGHIJKJIHGFEDCBA............\n...........ABCDEFGHIJKLKJIHGFEDCBA...........\n..........ABCDEFGHIJKLMLKJIHGFEDCBA..........\n.........ABCDEFGHIJKLMNMLKJIHGFEDCBA.........\n........ABCDEFGHIJKLMNONMLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDBCA.\nABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA");
        break;

        case 'X':
        printf("%s", ".......................A.......................\n......................ABA......................\n.....................ABCBA.....................\n....................ABCDCBA....................\n...................ABCDEDCBA...................\n..................ABCDEFEDCBA..................\n.................ABCDEFGFEDCBA.................\n................ABCDEFGHGFEDCBA................\n...............ABCDEFGHIHGFEDCBA...............\n..............ABCDEFGHIJIHGFEDCBA..............\n.............ABCDEFGHIJKJIHGFEDCBA.............\n............ABCDEFGHIJKLKJIHGFEDCBA............\n...........ABCDEFGHIJKLMLKJIHGFEDCBA...........\n..........ABCDEFGHIJKLMNMLKJIHGFEDCBA..........\n.........ABCDEFGHIJKLMNONMLKJIHGFEDCBA.........\n........ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA...\n..ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDBCA..\n.ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIGHFEDCBA.\nABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA");
        break;

        case 'Y':
        printf("%s", "........................A........................\n.......................ABA.......................\n......................ABCBA......................\n.....................ABCDCBA.....................\n....................ABCDEDCBA....................\n...................ABCDEFEDCBA...................\n..................ABCDEFGFEDCBA..................\n.................ABCDEFGHGFEDCBA.................\n................ABCDEFGHIHGFEDCBA................\n...............ABCDEFGHIJIHGFEDCBA...............\n..............ABCDEFGHIJKJIHGFEDCBA..............\n.............ABCDEFGHIJKLKJIHGFEDCBA.............\n............ABCDEFGHIJKLMLKJIHGFEDCBA............\n...........ABCDEFGHIJKLMNMLKJIHGFEDCBA...........\n..........ABCDEFGHIJKLMNONMLKJIHGFEDCBA..........\n.........ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA.........\n........ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA....\n...ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDBCA...\n..ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIGHFEDCBA..\n.ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA");
        break;

        case 'Z':
        printf("%s", ".........................A.........................\n........................ABA........................\n.......................ABCBA.......................\n......................ABCDCBA......................\n.....................ABCDEDCBA.....................\n....................ABCDEFEDCBA....................\n...................ABCDEFGFEDCBA...................\n..................ABCDEFGHGFEDCBA..................\n.................ABCDEFGHIHGFEDCBA.................\n................ABCDEFGHIJIHGFEDCBA................\n...............ABCDEFGHIJKJIHGFEDCBA...............\n..............ABCDEFGHIJKLKJIHGFEDCBA..............\n.............ABCDEFGHIJKLMLKJIHGFEDCBA.............\n............ABCDEFGHIJKLMNMLKJIHGFEDCBA............\n...........ABCDEFGHIJKLMNONMLKJIHGFEDCBA...........\n..........ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA..........\n.........ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA.........\n........ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA........\n.......ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA.......\n......ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA......\n.....ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA.....\n....ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDBCA....\n...ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIGHFEDCBA...\n..ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA..\n.ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA.\nABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA");
        break;

    }
    return 0;
}



