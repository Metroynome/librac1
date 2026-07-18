#include <level.h>

int levelMaskHasMask(int value, int maskValue)
{
    return (value & maskValue) == maskValue;
}

int levelIdToMask(int levelId)
{
    switch (levelId) {
        case LEVEL_ID_MAIN_MENU: return LEVEL_MASK_MAIN_MENU;
        case LEVEL_ID_VELDIN1: return LEVEL_MASK_VELDIN1;
        case LEVEL_ID_NOVALIS: return LEVEL_MASK_NOVALIS;
        case LEVEL_ID_ARIDIA: return LEVEL_MASK_ARIDIA;
        case LEVEL_ID_KERWAN: return LEVEL_MASK_KERWAN;
        case LEVEL_ID_EUDORA: return LEVEL_MASK_EUDORA;
        case LEVEL_ID_RILGAR: return LEVEL_MASK_RILGAR;
        case LEVEL_ID_NEBULA_G34: return LEVEL_MASK_NEBULA_G34;
        case LEVEL_ID_UMBRIS: return LEVEL_MASK_UMBRIS;
        case LEVEL_ID_BATALIA: return LEVEL_MASK_BATALIA;
        case LEVEL_ID_GASPAR: return LEVEL_MASK_GASPAR;
        case LEVEL_ID_ORXON: return LEVEL_MASK_ORXON;
        case LEVEL_ID_POKITARU: return LEVEL_MASK_POKITARU;
        case LEVEL_ID_HOVEN: return LEVEL_MASK_HOVEN;
        case LEVEL_ID_OLTANIS_ORBIT: return LEVEL_MASK_OLTANIS_ORBIT;
        case LEVEL_ID_OLTANIS: return LEVEL_MASK_OLTANIS;
        case LEVEL_ID_QUARTU: return LEVEL_MASK_QUARTU;
        case LEVEL_ID_KALEBO: return LEVEL_MASK_KALEBO;
        case LEVEL_ID_VELDIN_ORBIT: return LEVEL_MASK_VELDIN_ORBIT;
        case LEVEL_ID_VELDIN2: return LEVEL_MASK_VELDIN2;
        default: return LEVEL_MASK_NONE;
    }
}

int levelMaskToId(int levelMask)
{
    switch (levelMask) {
        case LEVEL_MASK_MAIN_MENU: return LEVEL_ID_MAIN_MENU;
        case LEVEL_MASK_VELDIN1: return LEVEL_ID_VELDIN1;
        case LEVEL_MASK_NOVALIS: return LEVEL_ID_NOVALIS;
        case LEVEL_MASK_ARIDIA: return LEVEL_ID_ARIDIA;
        case LEVEL_MASK_KERWAN: return LEVEL_ID_KERWAN;
        case LEVEL_MASK_EUDORA: return LEVEL_ID_EUDORA;
        case LEVEL_MASK_RILGAR: return LEVEL_ID_RILGAR;
        case LEVEL_MASK_NEBULA_G34: return LEVEL_ID_NEBULA_G34;
        case LEVEL_MASK_UMBRIS: return LEVEL_ID_UMBRIS;
        case LEVEL_MASK_BATALIA: return LEVEL_ID_BATALIA;
        case LEVEL_MASK_GASPAR: return LEVEL_ID_GASPAR;
        case LEVEL_MASK_ORXON: return LEVEL_ID_ORXON;
        case LEVEL_MASK_POKITARU: return LEVEL_ID_POKITARU;
        case LEVEL_MASK_HOVEN: return LEVEL_ID_HOVEN;
        case LEVEL_MASK_OLTANIS_ORBIT: return LEVEL_ID_OLTANIS_ORBIT;
        case LEVEL_MASK_OLTANIS: return LEVEL_ID_OLTANIS;
        case LEVEL_MASK_QUARTU: return LEVEL_ID_QUARTU;
        case LEVEL_MASK_KALEBO: return LEVEL_ID_KALEBO;
        case LEVEL_MASK_VELDIN_ORBIT: return LEVEL_ID_VELDIN_ORBIT;
        case LEVEL_MASK_VELDIN2: return LEVEL_ID_VELDIN2;
        default: return 0;
    }
}

char * levelGetName(enum LEVEL_IDS levelId)
{
    switch (levelId) {
        case LEVEL_ID_MAIN_MENU: return "Main Menu";
        case LEVEL_ID_VELDIN1: return "Veldin 1";
        case LEVEL_ID_NOVALIS: return "Novalis";
        case LEVEL_ID_ARIDIA: return "Aridia";
        case LEVEL_ID_KERWAN: return "Kerwan";
        case LEVEL_ID_EUDORA: return "Eudora";
        case LEVEL_ID_RILGAR: return "Rilgar";
        case LEVEL_ID_NEBULA_G34: return "Nebula G34";
        case LEVEL_ID_UMBRIS: return "Umbris";
        case LEVEL_ID_BATALIA: return "Batalia";
        case LEVEL_ID_GASPAR: return "Gaspar";
        case LEVEL_ID_ORXON: return "Orxon";
        case LEVEL_ID_POKITARU: return "Pokitaru";
        case LEVEL_ID_HOVEN: return "Hoven";
        case LEVEL_ID_OLTANIS_ORBIT: return "Oltanis Orbit";
        case LEVEL_ID_OLTANIS: return "Oltanis";
        case LEVEL_ID_QUARTU: return "Quartu";
        case LEVEL_ID_KALEBO: return "Kalebo III";
        case LEVEL_ID_VELDIN_ORBIT: return "Veldin Orbit";
        case LEVEL_ID_VELDIN2: return "Veldin 2";
        default: return "Unknown";
    }
}
