//λ����
//ȥ�����һλ          | (101101->10110)           | x shr 1
//������һ��0         | (101101->1011010)         | x shl 1
//������һ��1         | (101101->1011011)         | x shl 1+1
//�����һλ���1       | (101100->101101)          | x or 1
//�����һλ���0       | (101101->101100)          | x or 1-1
//���һλȡ��          | (101101->101100)          | x xor 1
//��������kλ���1      | (101001->101101,k=3)      | x or (1 shl (k-1))
//��������kλ���0      | (101101->101001,k=3)      | x and not (1 shl (k-1))
//������kλȡ��         | (101001->101101,k=3)      | x xor (1 shl (k-1))
//ȡĩ��λ              | (1101101->101)            | x and 7
//ȡĩkλ               | (1101101->1101,k=5)       | x and (1 shl k-1)
//ȡ������kλ           | (1101101->1,k=4)          | x shr (k-1) and 1
//��ĩkλ���1          | (101001->101111,k=4)      | x or (1 shl k-1)
//ĩkλȡ��             | (101001->100110,k=4)      | x xor (1 shl k-1)
//���ұ�������1���0    | (100101111->100100000)    | x and (x+1)
//�������һ��0���1    | (100101111->100111111)    | x or (x+1)
//���ұ�������0���1    | (11011000->11011111)      | x or (x-1)
//ȡ�ұ�������1         | (100101111->1111)         | (x xor (x+1)) shr 1
//ȥ�������һ��1����� | (100101000->1000)         | x and (x xor (x-1))

//builtin����
int __builtin_ffs(int x);
int __builtin_ffsll(long long);
//Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.

int __builtin_clz(unsigned int x);
int __builtin_clzll(unsigned long long);
//Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.

int __builtin_ctz(unsigned int x);
int __builtin_ctzll(unsigned long long);
//Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.

int __builtin_clrsb(int x);
int __builtin_clrsbll(long long);
//Returns the number of leading redundant sign bits in x, i.e. the number of bits following the most significant bit that are identical to it. There are no special cases for 0 or other values.

int __builtin_popcount(unsigned int x);
int __builtin_popcountll(unsigned long long);
//Returns the number of 1-bits in x.

int __builtin_parity(unsigned int x);
int __builtin_parityll(unsigned long long);
//Returns the parity of x, i.e. the number of 1-bits in x modulo 2.

uint32_t __builtin_bswap32(uint32_t x);
uint64_t __builtin_bswap64(uint64_t x);
//Returns x with the order of the bytes reversed; for example, 0xaabb becomes 0xbbaa. Byte here always means exactly 8 bits.

//pb_ds��
//http://gaotianyu1350.gitcafe.io/2015/02/17/pbds/
//priority_queue
//����
//������ext/pb_ds/priority_queue.hpp
//������__gnu_pbds::priority_queue<T>
//ģ�������
//template<typename Value_Type,
//         typename Cmp_Fn = std::less<Value_Type>,
//         typename Tag = pairing_heap_tag,
//         typename Allocator = std::allocator<char>>
//class priority_queue;
//Value_Type������
//Cmp_Fn���Զ���Ƚ���
//Tag���ѵ����͡�������binary_heap_tag������ѣ�binomial_heap_tag������ѣ�rc_binomial_heap_tag pairing_heap_tag����Զѣ�thin_heap_tag
//Allocator�����ù�
//ʹ��
//���STL�е�priority_queue������
//��begin()��end()��ȡ�������Ӷ�����
//ɾ������Ԫ��void erase(point_iterator)
//���ӻ����ĳһԪ�ص�ֵvoid modify(point_iterator, const_reference)
//�ϲ�void join(priority_queue &other)����other�ϲ���*this������other���
//���ܷ���
//���ֲ�����push��pop��modify��erase��join
//pairing_heap_tag��push��joinO(1)�������̯O(logn)
//binary_heap_tag��ֻ֧��push��pop����Ϊ��̯O(logn)
//binomial_heap_tag��pushΪ��̯O(1)������ΪO(logn)
//rc_binomial_heap_tag��pushΪO(1)������ΪO(logn)
//thin_heap_tag��pushΪO(1)����֧��join������ΪO(logn)���������ֻ��increase_key��modify��̯O(1)
//��֧�ֲ��ǲ����ã���������������
//���½��ۣ�
//�����Ż�Dijkstra�㷨��pairing_heap_tag�ϸ����thin_heap_tag���ٶ�����д���ݽṹ�൱
//�߶����󷨺�
//binary_heap_tag�ھ���������������std::priority_queue
//pairing_heap_tag�ھ���������������binomial_heap_tag��rc_binomial_heap_tag
//ֻ��push��pop��join����ʱ��binary_heap_tag�ٶȽϿ�
//����modify����ʱ�����Կ���pairing_heap_tag��thin_heap_tag����д���ݽṹ

//Tree
//����
//������ext/pb_ds/assoc_container.hpp��ext/pb_ds/tree_policy.hpp
//������__gnu_pbds::tree<Key, T>
//ģ�������
//template<typename Key,
//         typename Mapped,
//         typename Cmp_Fn = std::less<Key>,
//         typename Tag = rb_tree_tag,
//         template<typename Const_Node_Iterator,
//                  typename Node_Iterator,
//                  typename Cmp_Fn_,
//                  typename Allocator_ >
//         class Node_Update = null_tree_node_update,
//         typename Allocator = std::allocator<char>>
//class tree;
//Tag��tree�����ͣ�������rb_tree_tag��splay_tree_tag��ov_tree_tag
//Node_Update������Ϊ�գ�Ҳ������pb_ds�Դ���tree_order_statistics_node_update���������tree�ͻ�����������find_by_order��order_of_key
//iterator find_by_order(size_type order)���ҵ�order + 1С��Ԫ�صĵ����������order̫��᷵��end()
//size_type order_of_key(const_key_reference r_key)��ѯ�����tree���ж��ٱ�r_keyС��Ԫ��
//ʹ��
//��mapʹ�÷���������ͬ������begin()��end()��size()��empty()��clear()��find(const Key)��
//lower_bound(const Key)��upper_bound(const Key)��erase(iterator)��erase(const Key)��
//insert(const pair<Key, T>)��operator[](const Key)
//�����ĳ�set��ֻ��Ҫ���ڶ�������Mapped��Ϊnull_type����4.4.0�����°汾�ı�������Ӧ��null_mapped_type���Ϳ����ˡ���ʱ������ָ������ͻ��pair���Key����set����û������
//��Ȼ����һЩ�����÷����磺
//void join(tree &other)����other������Ԫ���ƶ���*this�ϣ�ֵ�����ཻ��������׳��쳣��
//void split(const_key_reference r_key, tree &other)�����other��Ȼ���*this�����д���r_key��Ԫ���ƶ���other
//�Զ���Node_Updateʹ�÷���
//�Դ���tree_order_statistics_node_updateͳ�Ƶ�������size
//�Լ��޸ľͿ���ͳ�����׺ϲ���������Ϣ
//���´���ʵ�����������
//template<class Node_CItr, class Node_Itr,
//         class Cmp_Fn, class _Alloc>
//struct my_node_update {
//  virtual Node_CItr node_begin()const = 0;
//  virtual Node_CItr node_end()const = 0;
//  typedef int metadata_type; //�ڵ��ϼ�¼�Ķ�����Ϣ������
//  inline void operator()(Node_Itr it, Node_CItr end_it) {
//    Node_Itr l = it.get_l_child(), r = it.get_r_child();
//    int left = 0, right = 0;
//    if (l != end_it) { left = l.get_metadata(); }
//    if (r != end_it) { right = r.get_metadata(); }
//    const_cast<metadata_type &>(it.get_metadata()) = left + right + (*it)->second;
//  }
//  inline int prefix_sum(int x) {
//    int ans = 0;
//    Node_CItr it = node_begin();
//    while (it != node_end()) {
//      Node_CItr l = it.get_l_child(), r = it.get_r_child();
//      if (Cmp_Fn()(x, (*it)->first)) { it = l; }
//      else {
//        ans += (*it)->second;
//        if (l != node_end()) { ans += l.get_metadata(); }
//        it = r;
//      }
//    }
//    return ans;
//  }
//  inline int interval_sum(int l, int r) {
//    return prefix_sum(r) - prefix_sum(l - 1);
//  }
//};
//int main() {
//  __gnu_pbds::tree<int, int, std::less<int>, __gnu_pbds::rb_tree_tag, my_node_update> T;
//  T[2] = 100; T[3] = 1000; T[4] = 10000;
//  printf("%d\n", T.interval_sum(3, 4));
//  printf("%d\n", T.prefix_sum(3));
//}
//ע�⣺
//��Node_Itr�����������飺��get_l_child��get_r_child��ȡ���Ҷ��ӣ��������Ǻţ�һ���Ǻ�ֻ�ǻ�ȡ��iterator����ȡ�ڵ���Ϣ����get_metadata��ȡ�ڵ������Ϣ
//operator()�Ĺ����ǽ��ڵ�it����Ϣ���£������end_it��ʾ�սڵ�
//���ܷ���
//����д���ݽṹ��࣬rb_tree_tagҪ����

//Hash
//����
//������ext/pb_ds/assoc_container.hpp��ext/pb_ds/hash_policy.hpp
//������
//__gnu_pbds::cc_hash_table<Key, Mapped>
//__gnu_pbds::gp_hash_table<Key, Mapped>
//ʹ��
//֧��find��operator[]

//Trie
//����
//������ext/pb_ds/assoc_container.hpp��ext/pb_ds/trie_policy.hpp
//������__gnu_pbds::trie<Key, Mapped>
//ģ�������
//template<typename Key,
//         typename Mapped,
//         typename Cmp_Fn = std::less<Key>,
//         typename Tag = pat_trie_tag,
//         template<typename Const_Node_Iterator,
//                  typename Node_Iterator,
//                  typename E_Access_Traits_,
//                  typename Allocator_>
//         class Node_Update = null_trie_node_update,
//         typename Allocator = std::allocator<char>>
//class trie;
//Key is the key type.
//Mapped is the mapped-policy, and is explained in Tutorial::Associative Containers::Associative Containers Others than Maps.
//E_Access_Traits is described in Element-Access Traits.
//Tag specifies which underlying data structure to use, and is described shortly.
//Node_Update is a policy for updating node invariants. This is described in Node Invariants.
//Allocator is an allocator type.

//���ܣ�
//pair<const_iterator, const_iterator> prefix_range(key_const_reference)
//Finds the const iterator range corresponding to all values whose prefixes match r_key
//������������������trie��ģ���������ôдtrie<string, [your type here], string_trie_e_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>

//List������multimap/multiset��
//����
//������ext/pb_ds/assoc_container.hpp��ext/pb_ds/list_update_policy.hpp
//������__gnu_pbds::list_update<Key, Mapped>
//ģ�������
//template<typename Key,
//         typename Mapped,
//         typename Eq_Fn = std::equal_to<Key>,
//         typename Update_Policy = move_to_front_lu_policy<>,
//         typename Allocator = std::allocator<char>>
//class list_update;

//�ܽ�
//priority_queue����STL���֧����modify��erase��join
//tree���൱��STL�е�set/map����֧��split��join������tree_order_statistics_node_update��֧�ֲ�ѯrank��kСֵ���������Զ���Node_Update��ά��������Ϣ
//��Ŀǰ���������У�STLû�е�����hash_table
//������pb_ds����std::set/map/priority_queue����ʹ�����ø���
