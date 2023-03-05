#include <memory>
#include <stdio.h>
#include <vector>

#include "bing-bong.h"

int main(int, char **)
{
    // Initialise services
    std::shared_ptr binger = std::make_shared<Binger>();
    std::shared_ptr bonger = std::make_shared<Bonger>();

    // Configure entangled services, as they hold a reference to each other
    binger->setBonger(bonger);
    bonger->setBinger(binger);

    // Create vec of services for convenience
    std::vector<std::shared_ptr<Runnable>> services;
    services.emplace_back(std::static_pointer_cast<Runnable>(binger));
    services.emplace_back(std::static_pointer_cast<Runnable>(bonger));

    // Configure intial state
    binger->requestRun();

    for (int i = 0; i < 10; i++) {
        for (auto service : services) {
            service->run();
        }
    }

    return 0;
}
