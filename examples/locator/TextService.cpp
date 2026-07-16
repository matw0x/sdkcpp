#include "TextService.h"

#include "MusicService.h"

namespace myProject {

void TextService::parse() {
    auto& music = get<MusicService>();

    music.process();
}

}  // namespace myProject
