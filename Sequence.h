


class Sequence {

    public:
        Sequence();
        Sequence(const Sequence & seq); 
        ~Sequence();
        Sequence & operator=(const Sequence & seq);
        void insert(double num);
        void insert(double *array, int size);
        int find(double num) const;
        int size() const;
        double sum() const;
        double mean() const;
        double median() const;
        double stddev() const;
        Sequence concatenate(const Sequence & seq);
        void print();
        
    private:
        double *arr;
        int currentSize;
        int maxSize;
        bool isEmpty() const;
        void copySequence(const Sequence & seq);
        
};