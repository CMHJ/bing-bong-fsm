#include <stdio.h>
#include <memory>

class Runnable
{
public:
    virtual void run() = 0;
    virtual void requestRun() = 0;
};

class Bonger;

class Binger : public Runnable
{
    enum State
    {
        IDLE,
        BING
    };

public:
    Binger();
    void run();
    void requestRun();
    void setBonger(std::shared_ptr<Bonger> bonger);

private:
    State m_state;
    bool m_runRequested;
    std::shared_ptr<Bonger> m_bonger;
};

class Bonger : public Runnable
{
    enum State
    {
        IDLE,
        BONG
    };

public:
    Bonger();
    void run();
    void requestRun();
    void setBinger(std::shared_ptr<Binger> binger);

private:
    State m_state;
    bool m_runRequested;
    std::shared_ptr<Binger> m_binger;
};