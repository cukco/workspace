import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import minimize 

days = np.array([0, 0.25, 0.5, 1, 2, 3, 4, 5, 6, 8, 10])
micrograms = np.array([2.5, 3.6, 5.3, 9.5, 14.0, 16.5, 18.8, 21.5, 23.2, 26.8, 28.4])

def exponential_model(params, t):
    C = params[0] 
    a = params[1] 
    return C * (1 - np.exp(-a * t))

def objective_func(params, x_data, y_data):
    y_predicted = exponential_model(params, x_data)
    
    residuals = y_data - y_predicted
    
    ssr = np.sum(residuals ** 2)
    return ssr

initial_params = [10, 2] 

print("--- ĐANG THỰC HIỆN NHIỆM VỤ 6 ---")
print(f"Ước tính ban đầu: C = {initial_params[0]}, a = {initial_params[1]}")

result = minimize(
    objective_func,       
    initial_params,       
    args=(days, micrograms), 
    method='Nelder-Mead'  
)
if result.success:
    best_params = result.x
    best_C = best_params[0]
    best_a = best_params[1]
    
    final_ssr = result.fun

    print("\n--- KẾT QUẢ NHIỆM VỤ 6 ---")
    print(f"Các tham số phù hợp nhất (best-fit parameters) là:")
    print(f"  C (Lượng tối đa) = {best_C:.4f}")
    print(f"  a (Hằng số tốc độ) = {best_a:.4f}")
    print(f"\nTổng bình phương phần dư (SSR) của mô hình này: {final_ssr:.4f}")

    plt.figure(figsize=(10, 6))
    
    plt.plot(days, micrograms, 'bo', label='Dữ liệu thực nghiệm')
    
    days_smooth = np.linspace(min(days), max(days), 100)
    y_smooth_fit = exponential_model(best_params, days_smooth)
    
    plt.plot(days_smooth, y_smooth_fit, 'r-', linewidth=2, 
             label=f'Mô hình Gray-box\nC={best_C:.2f}, a={best_a:.2f}')
    
    plt.title('Nhiệm vụ 6: Mô hình Hàm mũ (Gray-box)')
    plt.xlabel('Ngày (Day)')
    plt.ylabel('Microgram thuốc được giải phóng (Micrograms)')
    plt.legend(loc='upper left')
    plt.grid(True)
    plt.show()

else:
    print("Quá trình cực tiểu hóa thất bại. Lỗi:")
    print(result.message)