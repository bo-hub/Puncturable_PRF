#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "GGMTree.h"
using  namespace  std;

void PPRF_compute_all_keys(const vector<GGMNode>& node_list, int level);
void PPRF_Eval(long msg );

unordered_map<long, uint8_t*> keys;

int main() {
    /*Setup  */
    uint8_t *key = (unsigned char*) "0123456789123456";
    GGMTree *tree;
    tree = new GGMTree(GGM_SIZE);

    /*Punc */
    vector<long> pos;
    for (int i = 0; i < GGM_SIZE; ++i) {
        pos.emplace_back(i);
    }
    vector<long> delete_pos ;
    delete_pos.emplace_back(1);

    vector<long> remain_pos;
    set_difference(pos.begin(), pos.end(),
                   delete_pos.begin(), delete_pos.end(),
                   inserter(remain_pos, remain_pos.begin()));

    vector<GGMNode> node_list;
    node_list.reserve(remain_pos.size()); //preallocate memory for vector
    for (long pos : remain_pos) {
        node_list.emplace_back(GGMNode(pos, tree->get_level()));
    }
    vector<GGMNode> remain_node = tree->min_coverage(node_list);

    for(auto & i : remain_node) {
        memcpy(i.key, key, AES_BLOCK_SIZE);
        GGMTree::derive_key_from_tree(i.key, i.index, i.level, 0);
    }
    /*Eval */
    keys.clear();

    PPRF_compute_all_keys(remain_node, tree->get_level());// precompute all keys of nodes

    PPRF_Eval(1);
    PPRF_Eval(2);
    PPRF_Eval(0);

    return 0;
}

void PPRF_Eval(long msg ){
    if(keys.find(msg) == keys.end()){
        cout << "stop at punctured point !" << endl;
    }
    else{
        cout <<"Original pseudo random value of  "<< msg << " is : " << endl;
        for (int j = 0 ; j <16; ++j){
            printf ( "%02x ",keys[msg][j]);
        }
        cout << endl ;
    }
}

void PPRF_compute_all_keys(const vector<GGMNode>& node_list, int level) {
    for(GGMNode node : node_list) {
        for (int i = 0; i < pow(2, level - node.level); ++i) {
            int offset = ((node.index) << (level - node.level)) + i;
            uint8_t derive_key[AES_BLOCK_SIZE];
            memcpy(derive_key, node.key, AES_BLOCK_SIZE);
            GGMTree::derive_key_from_tree(derive_key,  offset, level - node.level, 0);
            if(keys.find(offset) == keys.end()) {
                keys[offset] = (uint8_t*) malloc(AES_BLOCK_SIZE);
                memcpy(keys[offset], derive_key, AES_BLOCK_SIZE);
//                for (int j = 0 ; j <16; ++j){
//                    printf ( "%02x ",keys[offset][j]);
//                }
//                cout << endl;
            }
        }
    }
}
