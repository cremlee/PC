#ifndef FMU_RECIPE_H
#define FMU_RECIPE_H

class FMU_Recipe
{
public:
    FMU_Recipe();
    ~FMU_Recipe();
    int foam_density;
    int foam_temperature;
    int DisCycThe;
    int dispense_pump_speed;
    int milk_drain_time;
    int post_pump_speed;
    int post_pump_time;
    int rinse_pause_time;
    int rinse_water_pump_volume;
    int rinse_water_pump_temperature;
    int rinse_water_pump_speed;
    int rinse_air_time;
    int rinse_air_speed;

};

#endif // FMU_RECIPE_H
