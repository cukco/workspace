import numpy as np
import matplotlib.pyplot as plt

def analyze_polynomial_fit(x_data, y_data, degree):
    
    p = np.polyfit(x_data, y_data, degree)
    y_fit = np.polyval(p, x_data)
    
    residuals = y_data - y_fit
    
    sum_of_squares = np.sum(residuals ** 2)
    
    plt.figure(figsize=(10, 6))
    plt.plot(x_data, y_data, 'bo', label='Dữ liệu thực nghiệm')
    

    x_smooth = np.linspace(min(x_data), max(x_data), 100)
    y_smooth = np.polyval(p, x_smooth)
    plt.plot(x_smooth, y_smooth, 'r-', linewidth=2, label=f'Mô hình Bậc {degree}')
    
    plt.title(f'Nhiệm vụ 4: Mô hình Đa thức Bậc {degree}')
    plt.xlabel('Ngày (Day)')
    plt.ylabel('Microgram thuốc được giải phóng (Micrograms)')
    plt.legend(loc='upper left')
    plt.grid(True)

    plt.figure(figsize=(10, 6))
    plt.bar(x_data, residuals, color='gray', width=0.25, align='center', label='Phần dư')
    plt.axhline(0, color='red', linestyle='--')
    plt.title(f'Nhiệm vụ 4: Biểu đồ Phần dư (Bậc {degree})')
    plt.xlabel('Ngày (Day)')
    plt.ylabel('Phần dư (y_thực_tế - y_mô_hình)')
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    
    return p, residuals, sum_of_squares

days = np.array([0, 0.25, 0.5, 1, 2, 3, 4, 5, 6, 8, 10])
micrograms = np.array([2.5, 3.6, 5.3, 9.5, 14.0, 16.5, 18.8, 21.5, 23.2, 26.8, 28.4])


degrees_to_test = [1, 2, 3]

results = {}

print('--- ĐANG THỰC HIỆN NHIỆM VỤ 4 ---')
print('Đang tạo biểu đồ và tính toán...')

for deg in degrees_to_test:
    p, res, ssr = analyze_polynomial_fit(days, micrograms, deg)
    
    results[deg] = {
        'params': p,
        'residuals': res,
        'sum_of_squares': ssr
    }

plt.show()

print('\n--- KẾT QUẢ TÓM TẮT NHIỆM VỤ 4 ---')

for deg, data in results.items():
    print(f'\n--- Bậc {deg} ---')
    print(f'  Tham số (hệ số) p: {data["params"]}')
    print(f'  Tổng bình phương phần dư (SSR): {data["sum_of_squares"]:.4f}')
print("Đa thức bậc 3 phù hợp tốt nhất")