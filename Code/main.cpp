#include <iostream>
#include<fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include<fstream>
#define MAX_LEN 255
#include "defn.h"

#define	CAT_NAME_LEN	25
#define	APP_NAME_LEN	50
#define	VERSION_LEN	10
#define	UNIT_SIZE	3


//BST insertion
struct bst *newNode(app_info app_data)
{
    struct bst *temp=(struct bst *)malloc(sizeof(struct bst));
    temp->record= app_data;
    temp->left=temp->right=NULL;
    return temp;
}

struct bst *insert(struct bst *node,app_info app_data) {
    if(node==NULL){
        return newNode(app_data);
        printf("\nappName: %s in root",app_data.app_name);
    }
    if(app_data.price< node->record.price){
        node->left=insert(node->left,app_data);
    }
    else if(app_data.price< node->record.price)
    {
        node->right=insert(node->right,app_data);
    }
    //std::cout<< node <<" "<< " \n"  ;
    return node;

}

void inorder(bst *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
      std::cout<<ptr->record.app_name<<"\n";
        inorder(ptr->right);

    }

}

int count (struct bst *t){
    if (t==NULL)
        return 0;
    else
    {
       int count_left=count(t->left);
       int count_right=count(t->right);
        return count_left+count_right+1;
    }
}

void max_heapify(float *A,int m,int n){
    float t;
    int j;
    t=A[m];
    j=2*m;
    while (j<=n){
        if(j<n && A[j+1] >A[j])
            j=j+1;
        if (t>A[j])
            break;
        else if (t<=A[j]){
            A[j/2]=A[j];
            j=2*j;
        }

    }
    A[j/2]=t;
    return;

}


void build_maxheap(float *A, int n){
    int i;
    for (i = n/2; i >=1 ; i--) {
        max_heapify(A,i,n);
    }
}

struct query{
    char query_1[MAX_LEN];
};


void AppData(categories *pCategories, app_info *pInfo, bst *pEntry);

int n=3,m=4;

int main() {

    int found;



//reading stuff from txt
    char array_cmd[CAT_NAME_LEN];


    int x;
    char buffer[80];
    float appSize = 0.0;
    float appPrice = 0.0;


    int i1 = 0;

    fgets(buffer, sizeof(buffer), stdin);

    /* for (std::string line; std::getline(std::cin, line);) {
         array_cmd[i1] = line;
         //std::cout << array_cmd[i1] << std::endl;
         i1++;

     } */

    int noOfCategories;
    noOfCategories = atoi(buffer);

    struct categories *categories_array;
    struct app_info *app_array;
    struct bst *bst_array;


    categories_array = static_cast<categories *>(malloc(noOfCategories * sizeof(struct categories)));
    //not sure why this is wrong
    categories_array = static_cast<categories *>(malloc(noOfCategories * sizeof(struct categories)));

    app_array = static_cast<app_info *>(malloc(m * sizeof(struct app_info)));

    // hashTableEntry=malloc(k*sizeof (struct hash_table_entry));
    //AppData(categories_array,app_array,bst_array);
    // AppData(categories_array, app_array,bst_array);




    for (int i = 0; i < noOfCategories; ++i) {
        //std::string str_obj(array_cmd[i+1]);
        //char_arr = &str_obj[0];
        fgets(array_cmd, sizeof(array_cmd), stdin);
        strcpy(categories_array[i].category, array_cmd);
        categories_array[i].root = NULL;
        //std::cout<<categories_array[i].category<<"****"<<std::endl;

    }


    int numApps;
    fgets(buffer, sizeof(numApps), stdin);
    numApps = atoi(buffer);
    //std::cout<<numApps<<std::endl;



    for (int i = 0; i < numApps; ++i) {
        bst_array = static_cast<bst *>(malloc(sizeof(struct bst)));

        strcpy(bst_array->record.category, "");
        strcpy(bst_array->record.app_name, "");
        strcpy(bst_array->record.version, "");
        strcpy(bst_array->record.units, "");
        bst_array->record.size = 0.0;
        bst_array->record.price = 0.0;
        bst_array->left = NULL;
        bst_array->left = NULL;


        //fill in the bst array with the apps

        fgets(buffer, sizeof(buffer), stdin);
        strcpy(bst_array->record.category, buffer);


        fgets(buffer, sizeof(buffer), stdin);
        strcpy(bst_array->record.app_name, buffer);
        //std::cout<<bst_array[i].record.app_name<<std::endl;

        fgets(buffer, sizeof(buffer), stdin);
        strcpy(bst_array->record.version, buffer);

        fgets(buffer, sizeof(buffer), stdin);
        appSize = atof(buffer);
        bst_array->record.size = appSize;

        fgets(buffer, sizeof(buffer), stdin);
        strcpy(bst_array->record.units, buffer);

        fgets(buffer, sizeof(buffer), stdin);
        appPrice = atof(buffer);
        bst_array->record.price = appPrice;



        //std::cout << bst_array[i].record.app_name << std::endl;

        //insert(bst_array,bst_array[0].record);

        //search for the apprpriate category







    /*

        for (int j = 0; j < noOfCategories; ++j) {

            if (strcmp(bst_array->record.category, categories_array[i].category) == 0) {

                //struct bst* new_bst=categories_array[i].root;

                insert(bst_array, bst_array[j].record);
                std::cout << bst_array[j].record.app_name << std::endl;
                //inorder(bst_array);

            }

        } */


        for (int i = 0; i < noOfCategories; i++) {
            if (strcmp(bst_array->record.category, categories_array[i].category) == 0) {

                struct bst *currPtr = categories_array[i].root;

                found = 0;

                //check if root is empty or not, if it is assign the struct to the root else check where it needs to go
                if (categories_array[i].root == NULL) {
                    categories_array[i].root = bst_array;
                    printf("\nappName: %s in root", bst_array->record.app_name);
                    found = 1;
                }

                while (found == 0) {
                    if (bst_array->record.price < currPtr->record.price) {
                        if (currPtr->left == NULL) {
                            printf("\nappName: %s connected left to %s", bst_array->record.app_name,
                                   currPtr->record.app_name);
                            currPtr->left = bst_array;
                            found = 1;
                        } else {
                            currPtr = currPtr->left;
                        }
                    } else {
                        if (currPtr->right == NULL) {
                            printf("\nappName: %s connected right to %s", bst_array->record.app_name,
                                   currPtr->record.app_name);
                            currPtr->right = bst_array;
                            found = 1;
                        } else {
                            currPtr = currPtr->right;
                        }
                    }
                   //  inorder(currPtr);
                }
                //inorder(currPtr);
                //inorder(bst_array);
                break;

            }
        }
         }


    int noOfquery;
    fgets(buffer, sizeof(buffer), stdin);
    noOfquery = atoi(buffer);
    //std::cout<<noOfquery;



    //store query
    struct query *query_store;
    char query_cmd[MAX_LEN];

    query_store = static_cast<query *>(malloc(noOfquery * sizeof(struct query)));


    for (int i = 0; i < noOfCategories; ++i) {
        //std::string str_obj(array_cmd[i+1]);
        //char_arr = &str_obj[0];
        fgets(query_cmd, sizeof(query_cmd), stdin);
        strcpy(query_store[i].query_1, query_cmd);
        //std::cout<<query_store[i].query_1<<"****"<<std::endl;

    }





/*

    int noOfNodes = count(categories_array->root);
    //heap allocation
   float heap[noOfNodes];
    for (int i = 0; i < noOfNodes; ++i) {
        heap[i] = categories_array[i].root->record.price;

    }

    */




}






