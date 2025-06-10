import struct
import random
from pathlib import Path

def write_int32_list(filename, data):
    with open(filename, 'wb') as f:
        for x in data:
            f.write(struct.pack('<i', x))

def generate_variants(n, out, suffix):
    # 1) Aleatorio
    rnd = [random.randint(-2**31, 2**31-1) for _ in range(n)]
    write_int32_list(out/f'random_{suffix}.bin', rnd)

    # 2) Ascendente
    asc = sorted(rnd)
    write_int32_list(out/f'asc_{suffix}.bin', asc)

    # 3) Descendente
    write_int32_list(out/f'desc_{suffix}.bin', reversed(asc))

    # 4) Parcial: primera mitad ordenada, segunda mitad aleatoria
    half = n // 2
    part = asc[:half] + [random.randint(-2**31, 2**31-1) for _ in range(half)]
    write_int32_list(out/f'partial_{suffix}.bin', part)

    # 5) Duplicados: pool reducido de 100 valores
    pool = [random.randint(-1000, 1000) for _ in range(100)]
    dup = [random.choice(pool) for _ in range(n)]
    write_int32_list(out/f'dup_{suffix}.bin', dup)

def main():
    out = Path('.')  # carpeta de salida
    # Tamaños en MB (1024 MB = 1 GB)
    for size_mb in [1, 10, 50, 100, 250, 500, 1024]:
        # cada entero ocupa 4 bytes
        n = (size_mb * 1024**2) // 4
        suffix = f'{size_mb}MB'
        print(f'Generando variantes de {suffix} ({n} enteros)...')
        generate_variants(n, out, suffix)
        print(f'  → Listo: archivos *_{suffix}.bin')

if __name__ == '__main__':
    main()
