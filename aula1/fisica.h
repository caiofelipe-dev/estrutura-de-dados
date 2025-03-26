float pos_final_mruv(float s0, float v0, float a, float t) {
    return s0 + v0 * t + (a*t*t)/2;
}