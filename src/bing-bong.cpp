#include "bing-bong.h"

Binger::Binger() : m_state(State::IDLE), m_runRequested(false)
{
}

void Binger::run()
{
    switch (m_state)
    {
    case IDLE:
        if (m_runRequested)
            m_state = State::BING;


        break;

    case BING:
        printf("Bing!\n");
        if (m_bonger != nullptr)
            m_bonger->requestRun();
        m_state = State::IDLE;

        break;
    }
}

void Binger::requestRun()
{
    m_runRequested = true;
}

void Binger::setBonger(std::shared_ptr<Bonger> bonger)
{
    m_bonger = std::move(bonger);
}

Bonger::Bonger() : m_state(State::IDLE), m_runRequested(false)
{
}

void Bonger::run()
{
    switch (m_state)
    {
    case State::IDLE:
        if (m_runRequested)
            m_state = State::BONG;

        break;

    case State::BONG:
        printf("Bong!\n");
        if (m_binger != nullptr)
            m_binger->requestRun();

        m_state = State::IDLE;
        break;
    }
}

void Bonger::requestRun()
{
    m_runRequested = true;
}

void Bonger::setBinger(std::shared_ptr<Binger> binger)
{
    m_binger = std::move(binger);
}