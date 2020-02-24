//
// Created by JianquanWang on 2020/2/22.
//

#ifndef SRC_SOLUTION_HPP
#define SRC_SOLUTION_HPP

#include "../ListNode.hpp"
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
class Solution{
public:
    /** LeetCode 206. Reverse Linked List: Easy*/
    ListNode* reverseList(ListNode* head){
        if(!head){
            return nullptr;
        }
        if(!(head->next)){
            return head;
        }
        ListNode *newhead = nullptr;
        ListNode *next = nullptr;

        while(head) {
            next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
    }

    ListNode* reverseList_2(ListNode* head){
        if(!head){
            return nullptr;
        }
        if(!(head->next)){
            return head;
        }

        ListNode temphead(0);
        ListNode* next = nullptr;
        while(head){
            next = head->next;
            head->next = temphead.next;
            temphead.next = head;
            head = next;

        }
        return temphead.next;
    }
    /** LeetCode 92. Reverse Linked List II: Medium*/
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(!head){
            return nullptr;
        }
        int change_len = n - m + 1;
        ListNode* pre_head = nullptr;
        ListNode* result = head;
        int step = 0;

        while(head && --m){ // head move m-1 times
            pre_head = head;
            head = head->next;
        }

        ListNode * modified_list_tail = head;
        ListNode * newhead = nullptr;
        while(head && change_len){
            ListNode* next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
            change_len--;
        }

        modified_list_tail->next = head;
        if(pre_head){
            pre_head->next = newhead;
        }else{
            result = newhead;
        }
        return result;
    }

    /** LeetCode 21. Merge two sorted lists: Easy*/
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2){
        ListNode tempNode(0);
        ListNode *pre = &tempNode;
        while(L1 && L2){
            if(L1->val < L2->val){
                pre->next = L1;
                L1 = L1->next;
            }else{
                pre->next = L2;
                L2 = L2->next;
            }
            pre = pre->next;
        }
        if(L1){
            pre->next = L1;
        }
        if(L2){
            pre->next = L2;
        }
        return tempNode.next;
    }

    /** LeetCode 160. Intersection of Two Linked Lists: Easy*/

    ListNode* getIntersectionNode(ListNode* headA, ListNode * headB){
        set<ListNode*> myset;
        while(headA){
            myset.insert(headA);
            headA = headA->next;
        }
        while (headB){
            if(myset.find(headB) != myset.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
    /** the second method */
    int get_list_length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* forward_long_list(int long_len, int short_len, ListNode *head){
        int delta = long_len - short_len;
        while(head && delta){
            head = head->next;
            delta--;
        }
        return head;
    }
    ListNode* getIntersectionNode_2(ListNode* headA, ListNode* headB){
        int A_len = get_list_length(headA);
        int B_len = get_list_length(headB);
        if(A_len < B_len){
            headB = forward_long_list(B_len, A_len, headB);
        }else{
            headA = forward_long_list(A_len, B_len, headA);
        }
        while(headA && headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

  /** LeetCode 141. Linked List Cycle, 142. Linked List Cycle II: Medium*/
  ListNode* detectCycle(ListNode* head){
      set<ListNode*> myset;
      while(head){
          if(myset.find(head) != myset.end())
              return head;
          myset.insert(head);
          head = head->next;
      }
      return nullptr;
  }

    ListNode* detectCycle_2(ListNode* head){
      ListNode* p_slow = head;
      ListNode* p_fast = head;
      ListNode* meet = nullptr;
      while(p_fast){
          p_slow = p_slow->next;
          p_fast = p_fast->next;
          if(!p_fast){
              return nullptr;
          }
          p_fast = p_fast->next;
          if(p_fast == p_slow) {
              meet = p_fast;
              break;
          }
      }
      if(meet == nullptr){
          return nullptr;
      }
      while(head && meet){
          if(head == meet){
              return head;
          }
          head = head->next;
          meet = meet->next;
      }

      return nullptr;
  }

  /** LeetCode 86. Partition List: Medium*/
  ListNode* partition(ListNode* head, int x){
      ListNode less_head(0);
      ListNode more_head(0);
      ListNode* less_ptr = &less_head;
      ListNode* more_ptr = &more_head;
      while(head){
           // ListNode* next = head->next;
          if(head->val < x){
              less_ptr->next = head;
              less_ptr = head;
          }else{
              more_ptr->next = head;
              more_ptr = more_ptr->next;
          }
          head = head->next;
      }
      less_ptr->next = more_head.next;
      more_ptr->next = nullptr;
      return less_head.next;
  }

  /** LeetCode 138. Copy List with Random Pointer: Medium*/
  struct RandomListNode{
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x):label(x), next(nullptr), random(nullptr){}
  };

  RandomListNode* copyRandomList(RandomListNode* head){
      /**  用两个map做, map1<原链表节点地址, 节点位置>, map2<节点位置, 新链表节点地址>*/
      map<RandomListNode*, int> node_map; // 地址到节点位置的map
      vector<RandomListNode*> node_vec; // 使用vector根据存储节点位置访问地址
      RandomListNode* ptr = head;
      int i = 0;

      while(ptr){ // 将新链表节点push入node_vec
          node_vec.push_back(new RandomListNode(ptr->label));
          node_map[ptr] = i;
          ptr = ptr->next;
          i++;
      }
      node_vec.push_back(0);
      ptr = head;
      i = 0;
      while(ptr){
          node_vec[i]->next = node_vec[i+1];
          if(ptr->random){
              int id = node_map[ptr->random];
              node_vec[i]->random = node_vec[id];
          }
          ptr = ptr->next;
          i++;
      }
      return node_vec[0];

  }

};




#endif //SRC_SOLUTION_HPP
