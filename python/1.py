import numpy as np
import matplotlib.pyplot as plt

def fit_linear_model(x_data, y_data):
    p = np.polyfit(x_data, y_data, 1)

    y_fit = np.polyval(p, x_data)
    
    plt.figure(figsize=(10, 6))
    
    plt.plot(x_data, y_data, 'bo', label='Dữ liệu thực nghiệm')
    
    plt.plot(x_data, y_fit, 'r-', linewidth=2, label='Mô hình đường thẳng')
    
    plt.title('Nhiệm vụ 1: Mô hình đường thẳng (Đa thức Bậc 1)')
    plt.xlabel('Ngày (Day)')
    plt.ylabel('Microgram thuốc được giải phóng (Micrograms)')
    plt.legend(loc='upper left')
    plt.grid(True) 
    
    plt.show()
    
    return p, y_fit

days = np.array([0, 0.25, 0.5, 1, 2, 3, 4, 5, 6, 8, 10])
micrograms = np.array([2.5, 3.6, 5.3, 9.5, 14.0, 16.5, 18.8, 21.5, 23.2, 26.8, 28.4])


[params, y_fitted] = fit_linear_model(days, micrograms)

print('--- KẾT QUẢ NHIỆM VỤ 1 ---')
print(f'Các tham số (hệ số) của mô hình đường thẳng (bậc 1) là:')
print(params)

print(f'Phương trình: y = {params[0]:.4f} * x + {params[1]:.4f}')
