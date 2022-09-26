//
//  LoginUserService.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 26/09/22.
//

import Foundation
import Alamofire

class LoginUserService {
    
    func loginWithUser(email: String, password: String, sucess: @escaping (Login)-> Void, error: @escaping (Error)-> Void) {
        var parameter =  [String:Any]()
        parameter["email"] = email
        parameter["password"] = password
        
        NetworkService.request(url: "https://carteirada-back-end-production.up.railway.app/auth", method: .post, params: parameter, obj: Login.self){ result in
            sucess(result)
        } error: { e in
            debugPrint()
            print("\n\nO erro está aqui:\n======\n\(e)")
            error(e)
        }
    }
}
