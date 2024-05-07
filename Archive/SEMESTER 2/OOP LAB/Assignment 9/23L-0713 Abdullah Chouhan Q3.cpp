class real {
    private:
        int num;
    public:
        real(int num = 0) {
            this->num = num;
        }
        real deepcopy() {
            real r(num);
            return r;
        }
};