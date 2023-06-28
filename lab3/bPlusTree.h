#include <memory>
#include <vector>

template<typename DataType>
class BPlusNode {
    typedef std::shared_ptr<BPlusNode> Node_ptr;
public:
    bool leaf;
    unsigned size;
    std::vector<DataType> data;
    std::vector<Node_ptr> children;
    Node_ptr next_leaf;
    Node_ptr prev_leaf;
    Node_ptr parent;

    BPlusNode();
};


template<typename DataType>
class BPlusTree {
    typedef std::shared_ptr<BPlusNode<DataType>> Node_ptr;
private:
    unsigned _minimum_degree;
    unsigned _min_node_fill;
    unsigned _max_node_fill;
    Node_ptr _root;

    template<typename OStream>
    void _printStep(OStream& output, std::shared_ptr<BPlusNode<DataType>> node, int level);

    std::pair<Node_ptr,unsigned> _subtree_search(std::shared_ptr<BPlusNode<DataType>> subtree_root, const DataType& key);

    void _split_node(std::shared_ptr<BPlusNode<DataType>> node);

    std::pair<Node_ptr,unsigned> _subtree_insert(std::shared_ptr<BPlusNode<DataType>> subtree_root, const DataType& key);

    void _remove_from_node(Node_ptr node, unsigned index);

public:
    explicit BPlusTree(unsigned minimum_degree = 2);

    template<typename OStream>
    void print(OStream& output);

    template<typename OStream>
    void printSorted(OStream& output);

    bool includes(const DataType& key);

    void insert(const DataType& key);

    void remove(const DataType& key);
};
