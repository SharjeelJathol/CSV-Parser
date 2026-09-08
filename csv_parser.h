#ifndef CSV_PARSER_H
#define CSV_PARSER_H

typedef struct {
    long timestamp;
    float accel_x;
    float accel_y;
    float accel_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
} IMUReading;


/* CSV Parsing Functions */
// Parse a CSV file and return an array of IMUReading structs.
// Returns: Pointer to dynamically allocated array, or NULL on error.
// The caller must free the returned pointer.
IMUReading* parse_csv(const char* filename, size_t* num_readings);

// Free an array of IMUReading structs
void free_readings(IMUReading* readings);

/* Query Functions */
// Find all readings within a time range (inclusive)
// Returns: New dynamically allocated array of readings.
// The caller must free the returned pointer.
IMUReading* filter_by_time(const IMUReading* readings, size_t num_readings,
                           long start_time, long end_time, size_t* result_count);

// Find the reading with the highest acceleration magnitude
IMUReading* find_max_acceleration(const IMUReading* readings, size_t num_readings);

// Calculate the average acceleration for each axis
void average_acceleration(const IMUReading* readings, size_t num_readings,
                          float* avg_x, float* avg_y, float* avg_z);

/* Optional: Print Functions (Debugging) */
void print_reading(const IMUReading* reading);
void print_readings(const IMUReading* readings, size_t num_readings, const char* label);

#endif