#include <stdio.h>

// convierte los bytes a mb,gb and tb. abre tu cmd y coloca este comando: wmic logicaldisk get deviceid, freespace, size
void bytes_to_tb_gb_mb(unsigned long long bytes, double *tb, double *gb, double *mb) {
    *tb = bytes / (1024.0 * 1024 * 1024 * 1024);
    *gb = bytes / (1024.0 * 1024 * 1024);
    *mb = bytes / (1024.0 * 1024);
}

//aqui hace la conversion. bitch
void convert_storage(const char *device_id, unsigned long long free_space, unsigned long long size) {
    double free_space_tb, free_space_gb, free_space_mb;
    double size_tb, size_gb, size_mb;

//convierte_el_espacio_libre y tamaño-total    
    bytes_to_tb_gb_mb(free_space, &free_space_tb, &free_space_gb, &free_space_mb);
    bytes_to_tb_gb_mb(size, &size_tb, &size_gb, &size_mb);

//imprime bitch.    
    printf("\nDeviceID: %s\n", device_id);
    printf("FreeSpace: %llu bytes\n", free_space);
    printf("   En TB: %.2f TB\n", free_space_tb);
    printf("   En GB: %.2f GB\n", free_space_gb);
    printf("   En MB: %.2f MB\n", free_space_mb);
    printf("Size: %llu bytes\n", size);
    printf("   En TB: %.2f TB\n", size_tb);
    printf("   En GB: %.2f GB\n", size_gb);
    printf("   En MB: %.2f MB\n", size_mb);
}

int main() {
    //define los valores,id,size-libre and tamaño_total_en_bytes. bitch
    const char *device_id = "C:"; //igual aqui
    unsigned long long free_space = 171400630272; //cambia esta webada en tu caso
    unsigned long long size = 254695960576; //igual aqui cambialo en tu caso

    //llama la funcion y realiza la conversion. bitch
    convert_storage(device_id, free_space, size);

    return 0;
}
