class Foo {
public:
    mutex m1;
    int count=1;
    condition_variable cv;
    Foo() {
       
    }

    void first(function<void()> printFirst) {
        // unique_lock<mutex> lk (m1);
        // cv.wait(lk,[this](){return count==1;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk (m1);
        cv.wait(lk,[this](){return count==2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count++;
        cv.notify_all();
       
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(m1);
        cv.wait(lk,[this](){return count==3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
       
    }
};