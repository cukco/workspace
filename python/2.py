import numpy as np
import matplotlib.pyplot as plt

def fit_linear_model_and_residuals(x_data, y_data):

    n = 1 
    p = np.polyfit(x_data, y_data, n)
    y_fit = np.polyval(p, x_data)
    
    residuals = y_data - y_fit
    
    plt.figure(figsize=(10, 6)) 
    plt.plot(x_data, y_data, 'bo', label='Dữ liệu thực nghiệm')
    plt.plot(x_data, y_fit, 'r-', linewidth=2, label='Mô hình đường thẳng (Bậc 1)')
    plt.title('Nhiệm vụ 1: Biểu đồ điều chỉnh đường thẳng')
    plt.xlabel('Ngày (Day)')
    plt.ylabel('Microgram thuốc được giải phóng (Micrograms)')
    plt.legend(loc='upper left')
    plt.grid(True)
    
    plt.figure(figsize=(10, 6))
    
    plt.bar(x_data, residuals, color='gray', width=0.25, align='center', label='Phần dư')
    
    plt.axhline(0, color='red', linestyle='--')
    
    plt.title('Nhiệm vụ 2: Biểu đồ Phần dư (Residuals)')
    plt.xlabel('Ngày (Day)')
    plt.ylabel('Phần dư (y_thực_tế - y_mô_hình)')
    plt.legend()
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    
    plt.show()
    
    return p, y_fit, residuals

days = np.array([0, 0.25, 0.5, 1, 2, 3, 4, 5, 6, 8, 10])
micrograms = np.array([2.5, 3.6, 5.3, 9.5, 14.0, 16.5, 18.8, 21.5, 23.2, 26.8, 28.4])

[params, y_fitted, residuals] = fit_linear_model_and_residuals(days, micrograms)

print('--- KẾT QUẢ NHIỆM VỤ 2 ---')
print('Các phần dư (residuals) tại mỗi điểm dữ liệu là:')
print(residuals)

print('\n--- (Kết quả từ Nhiệm vụ 1) ---')
print(f'Phương trình: y = {params[0]:.4f} * x + {params[1]:.4f}')
sum_of_squares = np.sum(residuals ** 2)

print('\n--- KẾT QUẢ NHIỆM VỤ 3 ---')
print(f'Tổng bình phương của các phần dư (Sum of Squared Residuals) là:')
print(sum_of_squares)