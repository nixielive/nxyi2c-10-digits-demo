/**
 * @file from_nxyi2c_default.h
 * @author Takeshi Mori
 * @brief 
 * @note The original implementation can be found at nixielive/nxyi2c_default.
 * 
 * @copyright Copyright (c) 2021 Takeshi Mori All Rights reserved.
 * 
 */
#pragma once

// ====================
// from nxyi2c_defs.h (see: nxyi2c_default)
// ====================
/**
 * @struct NXYI2C_CMD
 * @brief I2C command data
 * 
 */
typedef struct _nxyi2c_cmd
{
    unsigned char command;
    signed short value;
} NXYI2C_CMD;

// commands
/**
 * @enum nxyi2c_commands
 * @brief Type of commands
 * 
 */
enum nxyi2c_commands
{
    nxyi2c_start = 0,
    nxyi2c_set_pattern = 1,
    nxyi2c_set_duration = 2,
    nxyi2c_set_number = 3,
    nxyi2c_set_dot = 4,
};

// ====================
// from glow_pattern_defs.h (see: nxyi2c_default)
// ====================
/**
 * @enum nxyi2c_patterns
 * @brief Lighting pattern of Nixie tube
 * 
 */
enum nxyi2c_patterns
{
    nxyi2c_pattern_off = 0,
    nxyi2c_pattern_show = 1,
    nxyi2c_pattern_fade_in = 2,
    nxyi2c_pattern_fade_out = 3,
    nxyi2c_pattern_fade_change = 4,
    nxyi2c_pattern_patapata = 5,
    nxyi2c_pattern_from_cloud = 6,
    nxyi2c_pattern_into_cloud = 7,
};

// ====================
// from cathode_control_defs.h (see: nxyi2c_default)
// ====================
/**
 * @enum nxyi2c_nums
 * @brief Glowing number in a Nixie tube
 * @note you can use 0 to 9 (-1 means not available)
 * 
 */
enum nxyi2c_nums
{
    nxyi2c_nums_none = -1
};

/**
 * @enum nxyi2c_dots
 * @brief Glowing dot in a Nixie tube
 * 
 */
enum nxyi2c_dots
{
    nxyi2c_dots_none = -1,
    nxyi2c_dots_left = 0,
    nxyi2c_dots_right = 1
};
