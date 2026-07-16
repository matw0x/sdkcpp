#pragma once

#include <sdk/Locator.h>

namespace myProject {

struct MusicService;
struct VideoService;
struct TextService;

using Services = sdk::locator::Pack<MusicService, VideoService, TextService>;

using XService = sdk::locator::Locator<Services>;

struct ServiceHubParams {
    int a = 12;
    int b = 34;
};

using ServiceHub = XService::Hub;

}  // namespace myProject
