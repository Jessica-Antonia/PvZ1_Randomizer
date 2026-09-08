//I'm doing it in a header file because I am lazy. It's Sunday.

#pragma once

#include <cstdint>
#include <random>
#include <chrono>
#include <string>

class PvZ1_Randomizer {

public:

    enum class Worlds {

        DAY,
        NIGHT,
        POOL,
        FOG,
        ROOF
    };

    enum class Plants {

        PEA_SHOOTER,
        SUNFLOWER,
        CHERRY_BOMB,
        WALL_NUT,
        POTATO_MINE,
        SNOWPEA,
        CHOMPER,
        REPEATER,
        PUFFSHROOM,
        SUNSHROOM,
        FUMESHROOM,
        GRAVEBUSTER,
        HYPNOSHROOM,
        SCAREDY_SHROOM,
        ICE_SHROOM,
        DOOM_SHROOM,
        LILYPAD,
        SQUASH,
        THREEPEATER,
        TANGLEKELP,
        JALAPENO,
        SPIKEWEED,
        TORCHWOOD,
        TALL_NUT,
        SEASHROOM,
        PLANTERN,
        CACTUS,
        BLOVER,
        SPLITPEA,
        STARFRUIT,
        PUMPKIN,
        MAGNET_SHROOM,
        CABBAGEPULT,
        FLOWERPOT,
        KERNELPULT,
        COFFEEBEAN,
        GARLIC,
        UMBRELLA_LEAF,
        MARIGOLD,
        MELONPULT,
        GATLINPEA,
        TWIN_SUNFLOWER,
        GLOOMSHROOM,
        CAT_TAIL,
        WINTERMELON,
        GOLD_MAGNET,
        SPIKEROCK,
        COB_CANNON,
        IMITATOR
    };

private:

    static constexpr int NUM_WORLDS = 5;
    static constexpr int NUM_LEVELS = 10;
    static constexpr int NUM_PLANTS = 49;

    std::mt19937 rng;

    Worlds currentWorld;
    uint8_t currentLevel;
    Plants currentPlant;

public:

    PvZ1_Randomizer()
        : rng(static_cast<unsigned int>(
              std::chrono::system_clock::now().time_since_epoch().count())),
          currentWorld(Worlds::DAY),
          currentLevel(1),
          currentPlant(Plants::PEA_SHOOTER)
    {}

    ~PvZ1_Randomizer() {}

    // Randomizes world, level, and plant together, and stores the result
    // internally so the getters below report on the same "roll".
    void randomize() {

        std::uniform_int_distribution<int> worldDist(0, NUM_WORLDS - 1);
        std::uniform_int_distribution<int> levelDist(1, NUM_LEVELS);
        std::uniform_int_distribution<int> plantDist(0, NUM_PLANTS - 1);

        currentWorld = static_cast<Worlds>(worldDist(rng));
        currentLevel = static_cast<uint8_t>(levelDist(rng));
        currentPlant = static_cast<Plants>(plantDist(rng));
    }

    Worlds getWorld() const {
        return currentWorld;
    }

    uint8_t getLevel() const {
        return currentLevel;
    }

    Plants getPlant() const {
        return currentPlant;
    }

    static std::string worldToString(Worlds world) {

        switch (world) {

            case Worlds::DAY:   return "Day";
            case Worlds::NIGHT: return "Night";
            case Worlds::POOL:  return "Pool";
            case Worlds::FOG:   return "Fog";
            case Worlds::ROOF:  return "Roof";
        }
        return "Unknown";
    }

    static std::string plantToString(Plants plant) {

        switch (plant) {

            case Plants::PEA_SHOOTER:     return "Peashooter";
            case Plants::SUNFLOWER:       return "Sunflower";
            case Plants::CHERRY_BOMB:     return "Cherry Bomb";
            case Plants::WALL_NUT:        return "Wall-nut";
            case Plants::POTATO_MINE:     return "Potato Mine";
            case Plants::SNOWPEA:         return "Snow Pea";
            case Plants::CHOMPER:         return "Chomper";
            case Plants::REPEATER:        return "Repeater";
            case Plants::PUFFSHROOM:      return "Puff-shroom";
            case Plants::SUNSHROOM:       return "Sun-shroom";
            case Plants::FUMESHROOM:      return "Fume-shroom";
            case Plants::GRAVEBUSTER:     return "Grave Buster";
            case Plants::HYPNOSHROOM:     return "Hypno-shroom";
            case Plants::SCAREDY_SHROOM:  return "Scaredy-shroom";
            case Plants::ICE_SHROOM:      return "Ice-shroom";
            case Plants::DOOM_SHROOM:     return "Doom-shroom";
            case Plants::LILYPAD:         return "Lily Pad";
            case Plants::SQUASH:          return "Squash";
            case Plants::THREEPEATER:     return "Threepeater";
            case Plants::TANGLEKELP:      return "Tangle Kelp";
            case Plants::JALAPENO:        return "Jalapeno";
            case Plants::SPIKEWEED:       return "Spikeweed";
            case Plants::TORCHWOOD:       return "Torchwood";
            case Plants::TALL_NUT:        return "Tall-nut";
            case Plants::SEASHROOM:       return "Sea-shroom";
            case Plants::PLANTERN:        return "Plantern";
            case Plants::CACTUS:          return "Cactus";
            case Plants::BLOVER:          return "Blover";
            case Plants::SPLITPEA:        return "Split Pea";
            case Plants::STARFRUIT:       return "Starfruit";
            case Plants::PUMPKIN:         return "Pumpkin";
            case Plants::MAGNET_SHROOM:   return "Magnet-shroom";
            case Plants::CABBAGEPULT:     return "Cabbage-pult";
            case Plants::FLOWERPOT:       return "Flower Pot";
            case Plants::KERNELPULT:      return "Kernel-pult";
            case Plants::COFFEEBEAN:      return "Coffee Bean";
            case Plants::GARLIC:          return "Garlic";
            case Plants::UMBRELLA_LEAF:   return "Umbrella Leaf";
            case Plants::MARIGOLD:        return "Marigold";
            case Plants::MELONPULT:       return "Melon-pult";
            case Plants::GATLINPEA:       return "Gatling Pea";
            case Plants::TWIN_SUNFLOWER:  return "Twin Sunflower";
            case Plants::GLOOMSHROOM:     return "Gloom-shroom";
            case Plants::CAT_TAIL:        return "Cattail";
            case Plants::WINTERMELON:     return "Winter Melon";
            case Plants::GOLD_MAGNET:     return "Gold Magnet";
            case Plants::SPIKEROCK:       return "Spikerock";
            case Plants::COB_CANNON:      return "Cob Cannon";
            case Plants::IMITATOR:        return "Imitator";
        }
        return "Unknown";
    }
};